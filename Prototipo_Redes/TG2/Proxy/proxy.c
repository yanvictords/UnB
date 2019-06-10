// Universidade de Brasília
// Author: Yan Victor
// Resume: This proxy is responsible for intercept the LAN traffic and drop blacklisted IP's

#include "proxy.h"

_Bool getAddrInBlackList (char * ipAddr) {
	char ipList[4096];
	FILE *file;

	if (!(file = fopen(_BLACKLIST_FILE, "r+"))) {
		printf("Blacklist file not found\n");
		return false;
	}
	
	while (!feof(file)) {
		fscanf(file, "%s\n", ipList);
		if (!strcmp(ipList, ipAddr)) {
			fclose(file);
			return true;
		}	
	}
	
	fclose(file);
	return false;
}

void putAddrInBlackList (char * ipAddr) {
	FILE *file;
	file = fopen(_BLACKLIST_FILE, "a+");
	
	fprintf(file, "%s\n", ipAddr);
	fclose(file);
}

void setBlackRule (char * ipAddr) {
	char rule[100];
	strcat(rule, "iptables -A INPUT -s ");
	strcat(rule, ipAddr);
	strcat(rule, " -j DROP");

	system(rule);
}

void blockIpAddr(char * ipAddr) {
	if (!getAddrInBlackList(ipAddr)) {
		putAddrInBlackList(ipAddr);
		setBlackRule(ipAddr);
	}
}

int main() {
	int proxy;
	char buffer[_LEN];

	printf("================ PROXY - TCP =================\n\n");

	int sck = socket(AF_INET, SOCK_STREAM, 0);
	if (sck == -1)
	{
		printf("A problem occurred while creating socket\n");
		exit(1);
	} else {
		printf("TCP socket created successfully!\n");
	}

	// Creating proxy server
	proxyServer.sin_family = AF_INET;
	proxyServer.sin_port = htons(_PORT);
	memset(proxyServer.sin_zero, 0x0, 8);

	// Trying to open port
	if (bind(sck, (struct sockaddr *) &proxyServer, sizeof(proxyServer)) == -1 )	{	
		printf("A problem ocurred while opening port %d!\n", _PORT);
		exit(1);
	} else {
		printf("The port %d was opened successfully!\n", _PORT);
	}

	printf("\nProxy server ON! Listening at %d\n", _PORT);
	printf("\nWaiting for connections...\n");

	listen(sck, 1);
	int serverSize = sizeof(server);

	_running = true;
	while (_running) {
		if ((proxy = accept(sck, (struct sockaddr*) &server, &serverSize)) == -1) {
			printf("\nA problem occurred while receiving a new connection!\n");
			exit(1);
		} else {
			printf("\nThe connection was established successfully!\n");
		}

		memset(buffer, 0x0, _LEN);
		printf("Waiting for new LAN connections...\n\n");

		int bufferSize;
		if ((bufferSize = recv(proxy, buffer, _LEN, 0)) > 0) {
			printf("=> NEW IP: %s\n", buffer);

			blockIpAddr(buffer);

			char response[_LEN];
			strcat(response, "The IP ");
			strcat(response, buffer);
			strcat(response, " was blocked successfully!");

			if(send(proxy, response, strlen(response), 0)) {
				printf("Sending message: %s\n", response);
			} else {
				printf("Failed to send message!\n");
			}
		}
	}

	close(sck);

	printf("\n\nEnding Proxy server...\n");
	return 0;
}	
