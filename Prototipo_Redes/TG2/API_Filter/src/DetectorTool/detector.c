#include "../../include/DetectorTool/detector.h"

#include "../../include/DetectorTool/ui.h"
#include "../../include/DetectorTool/record.h"
#include "../../include/DetectorTool/decoder.h"
#include "../../include/DetectorTool/identifier.h"

int detector (struct sockaddr_in addr, char * buffer, bool localNetHost) {
	int status;

	printBegin();
	status = packageAnalyzer(addr, buffer, localNetHost);
	printEnd();

	return status;
}

int packageAnalyzer (struct sockaddr_in addr, char * buffer, bool localNetHost) {
	// Checks if the ip address is already in the blacklist
	if (getAddrInBlackList(addr)) {
		printGetInBlackListStatus(_MODULE_ANALYZER, _REJECT_ADDR, addr);	
		return _REJECT_ADDR; // will be removed shortly	
	}
	
	// Checks if the protocol can be analyzed by this framework.
	int protocol = identifier(addr.sin_port); // gets the protocol

	if (!protocol) {
		printUnknownProtocol(_MODULE_ANALYZER);		
		printOkStatus(_MODULE_ANALYZER, _OK);	
		return _OK;
	}

	// Checks the operation type (REQUEST or RESPONSE)
	long long operation = decoder(protocol, buffer);

	// The operation is valid only if the package is a LAN request or WAN response
	if ((localNetHost && operation == _REQUEST) || (!localNetHost && operation == _RESPONSE)) {
		system("@cls||clear");
		printBegin();
		
		long long counter = record(addr.sin_addr, operation, protocol);

		#ifdef _DEBUGGER_MODE		
			printAllCounters(protocol);
		#endif

		// Is useful to analyze the counter only when is a WAN response
		if (!localNetHost) {
			return analyzePackageCounter(counter, addr, protocol);
		}
	}

	printOkStatus(_MODULE_ANALYZER, _OK);
	return _OK;
}

int analyzePackageCounter (long long counter, struct sockaddr_in addr, int protocol) {
	// If negative counter, probably the server is a reflector
	if (counter < _LOW_LIMIT) {
		// This module gives us certainty if the host is even a reflector
		// bool reflector = 	traceRouteAnalyzer(addr);	
		printErrorStatus(_MODULE_ANALYZER, _REF_ATTACK_ALERT, "Much more replies than requests was detected (Outside->Inside).");
		// if (reflector) 
		printAlert(_MODULE_ANALYZER, addr, protocol, counter);
		// else
			//	printAlertForgedReflector(_MODULE_ANALYZER, addr, protocol, counter);
		printPutInBlackListStatus(_MODULE_ANALYZER, _REJECT_ADDR, addr);
		putAddrInBlackList(addr);
		return _REF_ATTACK_ALERT;
	}

	printOkStatus(_MODULE_ANALYZER, _OK);
	return _OK; // the package can ben forwarded without problems
}

bool getAddrInBlackList (struct sockaddr_in addr) {
	char ipAddr[4096];
	char node_addr[4096];
	FILE *file;

	if (!(file = fopen(_BLACK_LIST_FILE, "r+"))) {
		printFileNotFound(_MODULE_ANALYZER, _BLACK_LIST_FILE);
		return false;
	}
	
	inet_ntop(AF_INET, &(addr.sin_addr), node_addr, INET_ADDRSTRLEN);

	while (!feof(file)) {
		fscanf(file, "%s\n", ipAddr);
		if (!strcmp(ipAddr, node_addr)) {
			fclose(file);
			return true;
		}	
	}
	
	fclose(file);
	return false;
}

void putAddrInBlackList (struct sockaddr_in addr) {
	char node_addr[4096];
	FILE *file;

	file = fopen(_BLACK_LIST_FILE, "a+");
	inet_ntop(AF_INET, &(addr.sin_addr), node_addr, INET_ADDRSTRLEN);
	
	fprintf(file, "%s\n", node_addr);
	fclose(file);
}
