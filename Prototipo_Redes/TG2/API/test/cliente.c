// UNIVERSIDADE DE BRASÍLIA
// YAN VICTOR DOS SANTOS
// Code for testings

#include "essential.h"
struct sockaddr_in source, server;

#define _DEST_PORT 3000
#define _SOURCE_PORT 4000
#define _IP "192.168.25.6"
#define _LEN 65536

_Bool _running = true;

void printHost (struct sockaddr_in * host) {
	char node_addr[4096];
	inet_ntop(AF_INET, &(host->sin_addr), node_addr, INET_ADDRSTRLEN);

	printf("\nPrint Host: [%s:%d]\n", node_addr, htons(host->sin_port));
}

int main () {
	printf("================ CLIENT - UDP =================\n\n");

	int sck = socket(AF_INET, SOCK_DGRAM, 0);

	int len = sizeof(server);
	int slen;
	char buffer[_LEN];

	if (sck == -1) {
		perror("O socket nao foi criado com sucesso!\n");
		exit(1);	
	} else {
		printf("O socket foi criado com sucesso!\n");
	}

	source.sin_family = AF_INET;
	source.sin_port = htons(_SOURCE_PORT);
	memset(source.sin_zero, 0x0, 8);

   if (bind(sck, (struct sockaddr *) &source, sizeof(source)) < 0) {
        perror("bind");
        exit(1);
    }

	server.sin_family = AF_INET;
	server.sin_port = htons(_DEST_PORT);
	server.sin_addr.s_addr = inet_addr(_IP);
	memset(server.sin_zero, 0x0, 8);

	struct sockaddr *cast_server = (struct sockaddr *) &server;
	int tam_addr_server = sizeof(server);
    unsigned char* ip;

	_running = true;
	while (_running) {
		printf("Sending the following text: Hello Server!\n");

		if (sendto(sck, "Hello Server!", sizeof("Hello Server!"), 0, cast_server, tam_addr_server)) {
			printf("\nWaiting for server response...\n");
		} else {
			printf("The server doesn't received the message...\n");
		}

		if ((slen = recvfrom(sck, buffer, _LEN, 0, cast_server, &tam_addr_server)) > 0) {
			buffer[slen] = '\0';
			printf("Buffer content: %s\n", buffer);
			printHost((struct sockaddr_in *) cast_server);
		}

		getchar();
	}

	close(sck);

	printf("\n\nEnding the client...\n");
	return 0;
}
