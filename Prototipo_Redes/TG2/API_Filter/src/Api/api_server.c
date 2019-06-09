#include "../../include/essential.h"
#include "../../include/Api/utils.h"
#include "../../include/Api/socket.h"
#include "../../include/DetectorTool/detector.h"
#include <stdbool.h>
#include "pthread.h"

#define _BUFFER_SIZE 65536
#define _LOW_BUFFER_SIZE 4096

pthread_mutex_t toSend = PTHREAD_MUTEX_INITIALIZER;
struct sockaddr_in _midServer;
struct sockaddr_in _sourceAddr;
struct sockaddr_in _destinyAddr;
int _status;
int _sckRaw;
_Bool _running;
_Bool _isLocal;

void startApiServer();
_Bool ifLanIpAddress(struct in_addr ipAddr);
_Bool ifIsUdpProtocol(char * buffer);
void * blackListSender(void *);

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
	struct sockaddr_in * hostToAnalyzer;
	char buffer[_BUFFER_SIZE];
	long bufferSize;

	printf("[%s]: Starting Api server...\n", _API_SERVER);
	_sckRaw = createSocket(_RAW_ETH);
	setEthHeaderInSocket(_sckRaw);

	while (_running) {	
		memset(buffer, 0x0, _BUFFER_SIZE);

		if (bufferSize = listenToPackages(_RAW_ETH, _sckRaw, buffer, _BUFFER_SIZE, &_destinyAddr) > 0
				&& ifIsUdpProtocol(buffer)) {	 
			
			printAllPacketContent(buffer);
			_isLocal = ifLanIpAddress(getSAddrFromBuffer(buffer));
			_sourceAddr = mountAddr(getSAddrFromBuffer(buffer).s_addr, getSPortFromBuffer(buffer));
			_destinyAddr = mountAddr(getDAddrFromBuffer(buffer).s_addr, getDPortFromBuffer(buffer));
			
			hostToAnalyzer = _isLocal ? &_destinyAddr : &_sourceAddr;
			_status = detector(*hostToAnalyzer, getPayload(buffer), _isLocal);

			if (_status < 0) {
				char * ipToBlock = inet_ntoa(hostToAnalyzer->sin_addr);

				pthread_t worker;
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
	int sckTcp = createSocket(_TCP);
	char * ipToBlock = (char *) ipAddress;

	int status = connectSocket(sckTcp, _midServer);
	if (status != -1) {
		sendPackage(_TCP, sckTcp, ipToBlock, _midServer);
		printf("[%s] The IP address %s was sended to intermediate server successfully!\n", _API_SERVER, ipToBlock);
	}

	closeSocket(&sckTcp);
}