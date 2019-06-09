#include "../../include/essential.h"
#include "../../include/Api/utils.h"
#include "../../include/Api/socket.h"
#include "../../include/DetectorTool/detector.h"
#include <stdbool.h>
#include "pthread.h"

#define _BUFFER_SIZE 65536
#define _LOW_BUFFER_SIZE 4096

// ----- Global variables
struct sockaddr_in _midServer;
int _sckRaw;
_Bool _running;

// ----- Functions
void startApiServer();
_Bool ifLanIpAddress(struct in_addr ipAddr);
_Bool ifIsUdpProtocol(char * buffer);
void * blackListSender(void * ipAddress);

// ----- Main
int main () {
	system("@cls||clear");
	printf("\n*************************************************\n");
	printf("* Welcome to API Filter! Created by: Yan Victor *\n");
	printf("*************************************************\n\n");

	_midServer = mountCharAddrInfors("192.168.25.6", 7000);
	
	_running = true;
	startApiServer();
	
	closeSocket(&_sckRaw);
	return 0;
}

void startApiServer () {
	char buffer[_BUFFER_SIZE];
	long bufferSize;

	_sckRaw = createSocket(_RAW_ETH);
	if (_sckRaw == -1) {
		_running = false;
	}

	setEthHeaderInSocket(_sckRaw);

	printf("[%s]: Starting Api server...\n", _API_SERVER);
	
	while (_running) {	
		struct sockaddr_in * hostToAnalyzer;
		memset(buffer, 0x0, _BUFFER_SIZE);

		// Listening for incoming packages
		if (bufferSize = listenToPackages(_RAW_ETH, _sckRaw, buffer, _BUFFER_SIZE, hostToAnalyzer) > 0
				&& ifIsUdpProtocol(buffer)) {	 
			
			printAllPacketContent(buffer);

			bool isLocal = ifLanIpAddress(getSAddrFromBuffer(buffer));

			// Always gets the WAN address
			hostToAnalyzer = isLocal ? 
							mountAddr(getDAddrFromBuffer(buffer).s_addr, getDPortFromBuffer(buffer))
						: mountAddr(getSAddrFromBuffer(buffer).s_addr, getSPortFromBuffer(buffer));

			int status = detector(*hostToAnalyzer, getPayload(buffer), isLocal);

			// If status is -1, then the address analyzed is a reflector
			if (status < 0) {
				pthread_t worker;
				char * ipToBlock = inet_ntoa(hostToAnalyzer->sin_addr);

				// Sending to the intermediate server that is responsible for dropping packages coming from blacklisted addresses
				pthread_create(&worker, NULL, blackListSender, (void *) ipToBlock);
			}
		}
	}
}

_Bool ifLanIpAddress (struct in_addr ipAddr) {
	return strncmp("10", inet_ntoa(ipAddr), sizeof("10")) == 0
		|| strncmp("172.16", inet_ntoa(ipAddr), sizeof("172.16")) == 0
		|| strncmp("192.168", inet_ntoa(ipAddr), sizeof("192.168")) == 0;
}

_Bool ifIsUdpProtocol (char * buffer) {
	struct iphdr *ip_packet = (struct iphdr *)&buffer[_SIZE_OF_ETH];
	return ip_packet->protocol == _UDP_PROTOCOL;
}

void * blackListSender (void * ipAddress) {
	char * ipToBlock = (char *) ipAddress;
	int sckTcp = createSocket(_TCP);

	if (connectSocket(sckTcp, _midServer) != -1) {
		sendPackage(_TCP, sckTcp, ipToBlock, _midServer);
		printf("[%s] The IP address %s was sended to intermediate server successfully!\n", _API_SERVER, ipToBlock);
	}

	closeSocket(&sckTcp);
}