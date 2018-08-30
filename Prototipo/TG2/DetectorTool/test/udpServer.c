// UNIVERSIDADE DE BRASÍLIA - 2018/2
// YAN VICTOR DOS SANTOS
// SERVIDOR DE TESTE

#include "udpServer.h"

int main()
{
	startServer();
	return 0;
}

void startServer()
{
	pthread_t a[2];
	int *listen, *send;
	sck = socket(AF_INET, SOCK_DGRAM, 0);	
	checkSocket(sck);

	listen = (int *) malloc(sizeof(int));
	send = (int *) malloc(sizeof(int));
	*listen = 1;
	*send = 0;

	pthread_create(&a[0], NULL, toSend, (void *) (send));
	pthread_create(&a[1], NULL, toListen, (void *) (listen));
	pthread_join(a[0],NULL);
}

void checkSocket(int sck_server)
{
	if(sck_server == -1)
	{
		printf("There was a problem creating the socket\n");
		exit(1);
	}
	else
		printf("Socket was created successfully!\n");
}

void bindPort(struct sockaddr_in addr, int port)
{
	if (bind(sck, (struct sockaddr *) &addr, sizeof(addr)) == -1 )
	{	
		printf("There was a problem opening the port...\n");
		exit(1);
	}
	else
		printf("Port %d was opened successfully! Listening...\n", port);
}

void * toListen(void * args)
{
	int buffer_size;
	char buffer[_LEN], response[_LEN];
	char * completeBuf;

	// ---- main server
	mainServerListen.sin_family = AF_INET; 
	mainServerListen.sin_port = htons(_LOCAL_PORT);
	mainServerListen.sin_addr.s_addr = htonl(INADDR_ANY);
	memset(mainServerListen.sin_zero, 0x0, 8);	
	int sizeAddr = sizeof(mainServerListen);

	bindPort(mainServerListen, _LOCAL_PORT);

	while (true)
	{
		if (buffer_size = recvfrom(sck,(char*)buffer, _LEN, 0, (struct sockaddr*)&mainServerListen, &sizeAddr) <= 0)
    	    printf("\nRecvfrom main server failed!\n");
		else
			printf("\nPackage was received successfully!\nBuffer size: %d\nContent: %s\n", buffer_size, buffer);
	}
}

void * toSend(void * args)
{
	char buffer[_LEN + _LEN];
	char *bufferFinal;

	// ---- main server
	mainServerSend.sin_family = AF_INET; 
	mainServerSend.sin_port = htons(_MAIN_SERV_PORT);
	mainServerSend.sin_addr.s_addr = inet_addr(_MAIN_ADDR);
	memset(mainServerSend.sin_zero, 0x0, 8);	
	int sizeAddr = sizeof(mainServerSend);
	int * sizeRealAddr;

	while (true)
	{
		// ---- non-local server
		realServerAddress = (struct sockaddr_in *) buffer;
		realServerAddress->sin_family = AF_INET; 
		realServerAddress->sin_port = htons(_REAL_SERV_PORT);
		realServerAddress->sin_addr.s_addr = inet_addr(_REAL_ADDR);
		memset(realServerAddress->sin_zero, 0x0, 8);	

		unsigned char host[_LEN];
		printf("\n=> TYPE THE HOST: ");
		scanf("%s", host);
		
		mountDnsPackage((unsigned char) _QUERY, &buffer[_HEADER_ADDR_SZ], host);

		int buffer_size = _HEADER_ADDR_SZ + sizeof(struct DNS_H);

		if (sendto(sck, (char*) buffer, buffer_size, 0, (struct sockaddr*)&mainServerSend, sizeAddr) < 0)
	        printf("\nSendto local host failed!\n");
		else
			printf("\nThe package was forwarded to local host successfully!\n");
	}
}
