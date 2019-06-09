#include "../../include/DetectorTool/ui.h"

#include <time.h>

void printBegin () {
	printf("\n================== DETECTOR MODULE ==================\n");
	printf("|Analyzing packet...\n");
	/*PRINT_COLOR(RED, "\ntestando");
	PRINT_COLOR(BOLD_RED, "testando");
	PRINT_COLOR(GREEN, "testando");
	PRINT_COLOR(BOLD_GREEN, "testando");
	PRINT_COLOR(YELLOW, "testando");
	PRINT_COLOR(BOLD_YELLOW, "testando");
	PRINT_COLOR(BLUE, "testando");
	PRINT_COLOR(BOLD_BLUE, "testando");
	PRINT_COLOR(CYAN, "testando");
	PRINT_COLOR(BOLD_CYAN, "testando");
	PRINT_COLOR(MAGENTA, "testando");
	PRINT_COLOR(BOLD_MAGENTA, "testando\n");*/
}

void printEnd () {
	printTime();
	printf("\n=============== END - DETECTOR MODULE ===============\n\n");
}

void printQueryType (char * module, int operation) {
	if (operation == 1)
		printf("[%s]: The package is a QUERY/REQUEST\n", module);
	else if (operation == (-1))
		printf("[%s]: The package is a RESPONSE\n", module);
	else
		printf("[%s]: The package type is UNKNOWN\n", module);
}

void printUnknownProtocol (char * module) {
	printf("[%s]: Unknown protocol. The packet can't be decoded...\n", module);
}

void printOkStatus (char * module, int status) {
	printf("[%s]: Status %d. The package can be forwarded without problems!\n", module, status);
}

void printErrorStatus (char * module, int status, char * exception) {
	printf("[%s]: Status %d. [ERROR] A problem was detected!\n=> Thrown Exception: %s\n", module, status, exception); 	
}

void printAnotherStatus (char * module, int status, char * event) {
	printf("[%s]: Status %d. Event Description: %s\n", module, status, event);
}

void printGetInBlackListStatus (char * module, int status, struct sockaddr_in addr) {
	char node_addr[4096];
	inet_ntop(AF_INET, &(addr.sin_addr), node_addr, INET_ADDRSTRLEN);
	printf("[%s]: Status %d. [BLACKLIST] The host %s was found in the blacklist.\n@Action: All packets from this host must to be BLOCKED!\n", module, status, node_addr);
}

void printPutInBlackListStatus (char * module, int status, struct sockaddr_in addr) {
	char node_addr[4096];
	inet_ntop(AF_INET, &(addr.sin_addr), node_addr, INET_ADDRSTRLEN);
	printf("[%s]: Status %d. [BLACKLIST] The host %s was listed in the blacklist.\n@Action: All packets from this host must to be BLOCKED from now on!\n", module, status, node_addr);
}

void printFileNotFound (char * module, char * file) {
	printf("[%s]: [ERROR] File %s was not found!\n", module, file);
}

void printProtocolName (char * module, int protocol) {
	printf("[%s]: %s protocol detected.\n", module, getProtocolName(protocol));
}

void printAlert (char * module, struct sockaddr_in addr, int protocol, int counter) {
	char node_addr[4096];
	inet_ntop(AF_INET, &(addr.sin_addr), node_addr, INET_ADDRSTRLEN);

	PRINT_COLOR(RED, "\n************************ ALERT ****************************\n");
	printf("[%s]: The non-local server is being a reflector candidate!\n", module);
	printf("Host Ip Address: %s:%d ~ %s protocol package\n", node_addr, htons(addr.sin_port), getProtocolName(protocol));
	printf("Counter: %d\n", counter);
	PRINT_COLOR(RED, "************************ ALERT ****************************\n\n");
}

void printAlertForgedReflector (char * module, struct sockaddr_in addr, int protocol, int counter) {
	char node_addr[4096];
	inet_ntop(AF_INET, &(addr.sin_addr), node_addr, INET_ADDRSTRLEN);

	printf("\n************************ALERT****************************\n");
	printf("[%s]: The non-local server was detected like a forged reflector!\n", module);
	printf("Host Ip Address: %s:%d ~ %s protocol package\n", node_addr, htons(addr.sin_port), getProtocolName(protocol));
	printf("Counter: %d\n", counter);
	printf("************************ALERT****************************\n\n");
}

void printTime () {
	time_t mytime = time(NULL);
    char * time_str = ctime(&mytime);
    time_str[strlen(time_str)-1] = '\0';
    printf("[%s]", time_str);
}

char * getProtocolName (int protocol) {
	switch (protocol)
	{
		case 1: //dns
			return "DNS";
		case 2: //ntp
			return "NTP";		
		case 3: //snmp
			return "SNMP";
		case 4: //ssdp
			return "SSDP";
	}
	return "UNKNOWN";
}
