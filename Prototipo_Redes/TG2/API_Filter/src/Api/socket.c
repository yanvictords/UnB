#include "../../include/essential.h"
#include "../../include/Api/socket.h"

#include <netdb.h>
#include <inttypes.h>
#include <sys/types.h>
#include <sys/socket.h>
	
int createSocket (int type) {
	int sck;
	char sckTypeName[8];
	
	switch (type) {
		case _TCP:
			sck = socket(AF_INET, SOCK_STREAM, 0);
			strcpy(sckTypeName, "TCP");
			break;
		case _UDP:
			sck = socket(AF_INET, SOCK_DGRAM, 0);
			strcpy(sckTypeName, "UDP");
			break;
		case _RAW_ETH:
			sck = socket(AF_PACKET , SOCK_RAW, htons(ETH_P_ALL));
			strcpy(sckTypeName, "RAW ETH");
			break;
	}

	if (sck < 0) {
		printf("[%s]: There was a problem creating the socket.\n", _SOCKET);
		exit(1);
	} else {
		printf("[%s]: Socket %s was successfully created!\n", _SOCKET, sckTypeName);
	}

	return sck;
}

void bindPort (int sck, struct sockaddr_in addr) {
	if (bind(sck, (struct sockaddr *) &addr, sizeof(addr)) == -1 ) {	
		printf("[%s]: There was a problem opening the port %d...\n", _SOCKET, htons(addr.sin_port));
		perror("erro");
		exit(1);
	} else {
		printf("[%s]: Port %d was successfully opened! Listening...\n", _SOCKET, htons(addr.sin_port));
	}
}

int connectSocket (int socket, 	struct sockaddr_in server) {
	int status; 

	if (status = connect(socket, (struct sockaddr *) &server, sizeof(server)) == -1) {
		printf("The intermediate server isn't available!\n");	
	}	else {
		printf("The connection with intermediate server was established!\n");
	}

	return status;
}

void setEthHeaderInSocket (int socket) {
	struct ifreq ifr;
	memset(&ifr, 0, sizeof(ifr));
	snprintf(ifr.ifr_name, sizeof(ifr.ifr_name), _API_INTERFACE);
	
	if (ioctl(socket, SIOCGIFINDEX, &ifr) < 0) {
    	perror("ioctl(): error ");
    	exit(1);
	}
	if (setsockopt(socket, SOL_SOCKET, SO_BINDTODEVICE , (void *)&ifr, sizeof(ifr)) < 0) {
		printf("[%s]: There was a problem binding interface %s to socket\n", _SOCKET, _API_INTERFACE);
		exit(1);
	}	else {
		printf("[%s]: Binding socket to interface %s occurred successfully!\n", _SOCKET, _API_INTERFACE);
	}
}

ssize_t listenToPackages (int type, int socket, char *buffer, int bufferSize, struct sockaddr_in * source) {
	int sizeAddr = sizeof(*source);

	switch (type) {
		case _RAW_ETH:
		case _UDP:
			return recvfrom(socket, buffer, bufferSize, 0, (struct sockaddr*) source, &sizeAddr);
		case _TCP:
			return recv(socket, buffer, bufferSize, 0);
	}
}

ssize_t sendPackage (int type, int socket, char * buffer, struct sockaddr_in destiny)
{
	switch (type) {
		case _RAW_ETH:
		case _UDP:
			return sendto(socket, buffer, strlen(buffer), 0, (struct sockaddr*)&destiny, sizeof(destiny));
		case _TCP:
			return send(socket, buffer, strlen(buffer), 0);
	}
}

void closeSocket (int * socket) {
	close(*socket);
}