#include "../../include/essential.h"
#include "../../include/Api/utils.h"
#include "../../include/Api/socket.h"
#include "../../include/DetectorTool/detector.h"
#include "pthread.h"

#define _LOW_BUFFER_SIZE 4096

struct sockaddr_in _proxy;
int _sckRaw;
_Bool _running;

void processConfiguration();
void initConfiguration();
void printConfiguration();
void startApiServer();
_Bool queryDnsFromThisIpToRouter (_Bool isLocal, struct sockaddr_in * host);
_Bool ifLanIpAddress(struct in_addr ipAddr);
_Bool ifIsUdpProtocol(char * buffer);
void * blackListSender(void * ipAddress);

int main () {
	clearConsole();
	printf("\n***********************************************************\n");
	printf("* Welcome to API Reflectors Detection! Author: Yan Victor *\n");
	printf("***********************************************************\n\n");

    processConfiguration();

	_proxy = mountCharAddrInfors(_PROXY_IP, _PROXY_PORT);
	
	_running = true;
	startApiServer();
	
	closeSocket(&_sckRaw);
	return 0;
}

void processConfiguration() {
	initConfiguration();
	printConfiguration();
}

void initConfiguration () {
	FILE *file;
	char debug;
	if (!(file = fopen(_CONFIG_FILE, "r+"))) {
		printf("Settings file is missing. Failed to start Api :(.\n");
		exit(1);
	}

	fscanf(file, "######## API Settings ########\n");
	fscanf(file, "@proxy_server_address:\n*ip: %s\n*port: %d\n", _PROXY_IP, &_PROXY_PORT);
	fscanf(file, "@blacklist_name: %s\n", _BLACKLIST_FILE);
	fscanf(file, "@limit_of_packages: %lld\n", &_LOW_LIMIT);
	fscanf(file, "@debug_mode (y/n): %c\n", &debug);

	if (debug == 'y') {
		_DEBUG_MODE = 1;
	} else {
		_DEBUG_MODE = 0;
	}

	fclose(file);
}

void printConfiguration () {
	printf("=> Ambient Configuration: \n");
	printf("| Proxy: %s:%d\n", _PROXY_IP, _PROXY_PORT);
	printf("| BlackList name: %s\n", _BLACKLIST_FILE);
	printf("| Limit of packages: %lld\n", _LOW_LIMIT);

	if (_DEBUG_MODE) {
		printf("| Debug Mode: ON\n");
	} else {
		printf("| Debug Mode: OFF\n\n");
	}

	printf("\n...Press <ENTER> to start API...");
	getchar();
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

		// Listening to for incoming packages
		if (bufferSize = listenToPackages(_RAW_ETH, _sckRaw, buffer, _BUFFER_SIZE, hostToAnalyzer) > 0
				&& ifIsUdpProtocol(buffer)) {	 

			_Bool isLocal = ifLanIpAddress(getSAddrFromBuffer(buffer));

			// Always gets the WAN address
			hostToAnalyzer = isLocal ? mountAddr(getDAddrFromBuffer(buffer).s_addr, getDPortFromBuffer(buffer))
						: mountAddr(getSAddrFromBuffer(buffer).s_addr, getSPortFromBuffer(buffer));

			int status = 0;
			if (!queryDnsFromThisIpToRouter(isLocal, hostToAnalyzer)) {
				if (_DEBUG_MODE) {
					printAllPacketContent(buffer);
				}
				status = detector(*hostToAnalyzer, getPayload(buffer), isLocal);
			}

			// If status is -1, then the address analyzed is a reflector
			if (status < 0) {
				pthread_t worker;
				char * ipToBlock = inet_ntoa(hostToAnalyzer->sin_addr);

				// Sending to the proxy server that is responsible for dropping packages coming from blacklisted addresses
				pthread_create(&worker, NULL, blackListSender, (void *) ipToBlock);
			}
		}
	}
}

_Bool queryDnsFromThisIpToRouter (_Bool isLocal, struct sockaddr_in * host) {
    // TODO: host pode variar
	return isLocal && !strcmp(inet_ntoa(host->sin_addr), "192.168.15.1");
}

_Bool ifLanIpAddress (struct in_addr ipAddr) {
	char * ip = inet_ntoa(ipAddr);

	// Just for testings. The below ip address must be the client/reflector ip address used to testing
	if (_DEBUG_MODE) {
		_Bool localReflectors = strcmp(ip, "192.168.15.8") == 0;

		return (!localReflectors && (strncmp("10", ip, strlen("10")) == 0
			|| strncmp("172.16", ip, strlen("172.16")) == 0
			// || strncmp("127.0.0", ip, strlen("127.0.0")) == 0
			|| strncmp("192.168", ip, strlen("192.168")) == 0));
	}

	return strncmp("10", ip, strlen("10")) == 0
		|| strncmp("172.16", ip, strlen("172.16")) == 0
		// || strncmp("127.0.0", ip, strlen("127.0.0")) == 0
 		|| strncmp("192.168", ip, strlen("192.168")) == 0;
}

_Bool ifIsUdpProtocol (char * buffer) {
	struct iphdr *ip_packet = (struct iphdr *)&buffer[_SIZE_OF_ETH];
	return ip_packet->protocol == _UDP_PROTOCOL;
}

void * blackListSender (void * ipAddress) {
	clearConsole();

	char * ipToBlock = (char *) ipAddress;
	int sckTcp = createSocket(_TCP);

	if (connectSocket(sckTcp, _proxy) != -1) {
		sendPackage(_TCP, sckTcp, ipToBlock, _proxy);
		printf("[%s] The IP address %s was sended to proxy server successfully!\n", _API_SERVER, ipToBlock);
	}

	closeSocket(&sckTcp);
}