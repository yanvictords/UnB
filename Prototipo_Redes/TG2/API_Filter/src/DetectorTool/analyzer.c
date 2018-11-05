#include "../../include/DetectorTool/analyzer.h"

int analyzer(struct sockaddr_in addr, char * buffer, bool localNetHost)
{
	return packageAnalyzer(addr, buffer, localNetHost);
}

int packageAnalyzer(struct sockaddr_in addr, char * buffer, bool localNetHost)
{
	if(!localNetHost)
	{
		if(getAddrInBlackList(addr))
		{
			printGetInBlackListStatus(_MODULE_ANALYZER, _REJECT_ADDR, addr);	
			// return _REJECT_ADDR; // will be removed shortly	
			return _OK; // Now, the blacklisted IP will block in another local
		}
	}
	int protocol =		identifier(addr.sin_port); // gets the protocol
	
	if (!protocol) // the protocol isn't able to be analyzed by this framework. The package will be forwarded without problems
	{
		printUnknownProtocol(_MODULE_ANALYZER);		
		printOkStatus(_MODULE_ANALYZER, _OK);	
		return _OK;
	}
	int operation =		decoder(protocol, buffer); // gets the type of operation (REQUEST OR RESPONSE)

	// alter the counter if the local server is querying or the outside server (maybe a reflector) is responding
	if ((localNetHost && operation == _REQUEST) || (!localNetHost && operation == _RESPONSE))
	{
		int counter = 		record(addr.sin_addr, operation, protocol);
		#ifdef _DEBUGGER_MODE		
			printAllCounters(protocol);
		#endif
		if (!localNetHost) // analyze the counter if the package comes from outside
		{
			return analyzePackageCounter(counter, addr, protocol);
		}
	}

	// int this case, the package can be forwarded without problems
	printOkStatus(_MODULE_ANALYZER, _OK);
	return _OK;
}

int analyzePackageCounter(int counter, struct sockaddr_in addr, int protocol)
{
	if (counter < _LOW_LIMIT) // if negative counter, probably the server is a reflector
	{
		// bool reflector = 	traceRouteAnalyzer(addr); // This module gives us certainty if the host is even a reflector	
		printErrorStatus(_MODULE_ANALYZER, _REF_ATTACK_ALERT, "Much more replies than requests was detected (Outside->Inside).");
		// if (reflector) 
			printAlert(_MODULE_ANALYZER, addr, protocol, counter);
		// else
			//	printAlertForgedReflector(_MODULE_ANALYZER, addr, protocol, counter);
		printPutInBlackListStatus(_MODULE_ANALYZER, _REJECT_ADDR, addr);
		putAddrInBlackList(addr);
		// return _REF_ATTACK_ALERT;
		return _OK; // Now, the blacklisted IP will block in another local
	}

	printOkStatus(_MODULE_ANALYZER, _OK);
	return _OK; // the package can ben forward without problems
}

bool getAddrInBlackList(struct sockaddr_in addr)
{

	FILE *file;
	if(!(file = fopen(_BLACK_LIST_FILE, "r+")))
	{
		printFileNotFound(_MODULE_ANALYZER, _BLACK_LIST_FILE);
		return false;
	}

	char ipAddr[4096];
	char node_addr[40496];
	
	inet_ntop(AF_INET, &(addr.sin_addr), node_addr, INET_ADDRSTRLEN);

	while (!feof(file))
	{
		fscanf(file, "%s\n", ipAddr);
		if(!strcmp(ipAddr, node_addr))
		{
			fclose(file);
			return true;
		}	
	}
	
	fclose(file);
	return false;
}

void putAddrInBlackList(struct sockaddr_in addr)
{
	FILE *file;
	file = fopen(_BLACK_LIST_FILE, "a+");
	char node_addr[4096];
	inet_ntop(AF_INET, &(addr.sin_addr), node_addr, INET_ADDRSTRLEN);
	
	fprintf(file, "%s\n", node_addr);
	fclose(file);
}
