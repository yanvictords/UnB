#include "../../include/DetectorTool/detector.h"
#include "../../include/Api/utils.h"
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

	if (isBlackListed(addr)) {
		return rejectAddress();
	}
	
	int protocol = identifier(addr.sin_port);
	if (!protocol) {
		printUnknownProtocol(_MODULE_ANALYZER);		
		printOkStatus(_MODULE_ANALYZER, _OK);	
		return _OK;
	}

	long long operation = decoder(protocol, buffer);

	if ((localNetHost && operation == _REQUEST) || (!localNetHost && operation == _RESPONSE)) {
		long long counter = record(addr.sin_addr, operation, protocol);

		printAllCounters(protocol);

		if (!localNetHost) {
			return analyzePackageCounter(counter, addr, protocol);
		}
	}

	printOkStatus(_MODULE_ANALYZER, _OK);
	return _OK;
}

int rejectAddress () {
    printGetInBlackListStatus(_MODULE_ANALYZER, _REJECT_ADDR, addr);
    return _REJECT_ADDR;
}

int passBy

int analyzePackageCounter (long long counter, struct sockaddr_in addr, int protocol) {

	if (counter < (_LOW_LIMIT * (-1))	) {
		printErrorStatus(_MODULE_ANALYZER, _REF_ATTACK_ALERT, "Much more replies than requests was detected (Outside->Inside).");
		printAlert(_MODULE_ANALYZER, addr, protocol, counter);
		// else
			//	printAlertForgedReflector(_MODULE_ANALYZER, addr, protocol, counter);
		printPutInBlackListStatus(_MODULE_ANALYZER, _REJECT_ADDR, addr);
		putAddrInBlackList(addr);
		return _REF_ATTACK_ALERT;
	}

	printOkStatus(_MODULE_ANALYZER, _OK);
	return _OK;
}

_Bool isBlackListed (struct sockaddr_in addr) {
	char ipAddr[4096];
	char node_addr[4096];
	FILE *file;

	if (!(file = fopen(_BLACKLIST_FILE, "r+"))) {
		printFileNotFound(_MODULE_ANALYZER, _BLACKLIST_FILE);
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

	file = fopen(_BLACKLIST_FILE, "a+");
	inet_ntop(AF_INET, &(addr.sin_addr), node_addr, INET_ADDRSTRLEN);
	
	fprintf(file, "%s\n", node_addr);
	fclose(file);
}
