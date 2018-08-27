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
		printf("Houve problema ao criar socket\n");
		exit(1);
	}
	else
		printf("Socket criado com sucesso!\n");
}

void bindPort(int sck, struct sockaddr_in addr, int port)
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
	int sck_listen = socket(AF_INET, SOCK_DGRAM, 0);
	int buffer_size;
	char buffer[_LEN], response[_LEN];
	char * completeBuf;

	checkSocket(sck_listen);

	// ---- main server
	mainServerListen.sin_family = AF_INET; 
	mainServerListen.sin_port = htons(_LOCAL_PORT);
	mainServerListen.sin_addr.s_addr = htonl(INADDR_ANY);
	memset(mainServerListen.sin_zero, 0x0, 8);	
	int sizeAddr = sizeof(mainServerListen);

	bindPort(sck_listen, mainServerListen, _LOCAL_PORT);

	while (true)
	{
		if (buffer_size = recvfrom(sck_listen,(char*)buffer, _LEN, 0, (struct sockaddr*)&mainServerListen, &sizeAddr) <= 0)
    	    printf("Recvfrom main server failed!\n");
		else
		{
			printf("Buffer received successfully! Buffer size: %d\n", buffer_size);
			strcpy(response, "The message was received successfully!\n");
			if (sendto(sck_listen, (char*)response, _LEN, 0, (struct sockaddr*)&mainServerListen, sizeAddr) < 0)
		        printf("Sendto local host failed!\n");
			else
				printf("The package was forwarded to local host successfully!\n");
		}
	}
}

void * toSend(void * args)
{
	int sck_send = socket(AF_INET, SOCK_DGRAM, 0);
	char buffer[_LEN + _LEN];
	char *bufferFinal;
	checkSocket(sck_send);
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
		// sizeRealAddr = (int *) buffer;
		//int sizeReal = sizeof(realServerAddress);
		//*sizeRealAddr = sizeReal;

		unsigned char host[_LEN];
		printf("DIGITE O HOST: ");
		scanf("%s", host);
		
		mountDnsPackage((unsigned char) 0, &buffer[_HEADER_ADDR_SZ], host);

		printf("\nQUERYING: \n");
		struct sockaddr_in *addrData = (struct sockaddr_in *) buffer;

		char node_addr[_LEN];
		inet_ntop(AF_INET, &(addrData->sin_addr), node_addr, INET_ADDRSTRLEN);
		printf("IP: %s, port: %d\n",  node_addr, htons(addrData->sin_port));

		struct DNS_H *dns_aux;
	    dns_aux = (struct DNS_H *)&buffer[_HEADER_ADDR_SZ];
		printf("\nQUERY TYPE: %d\n", (int) dns_aux->qr);		

		int buffer_size = _HEADER_ADDR_SZ + sizeof(struct DNS_H);

		if (sendto(sck_send, (char*) buffer, buffer_size, 0, (struct sockaddr*)&mainServerSend, sizeAddr) < 0)
	        printf("Sendto local host failed!\n");
		else
		{
			printf("The package was forwarded to local host successfully!\n");
			if (recvfrom(sck_send,(char*)buffer, _LEN, 0, (struct sockaddr*)&mainServerSend, &sizeAddr) <= 0)
    		    printf("Recvfrom main server failed!\n");
			else
				printf("The response message was received successfully!\n");
		}
	}
}
