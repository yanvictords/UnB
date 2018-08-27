#include "../include/main_server.h"

int main()
{
	startServer();
	return 0;
}

void startServer()
{
	pthread_t a[2];
	int *local, *nonLocal;
	
	local = (int *) malloc(sizeof(int));
	nonLocal = (int *) malloc(sizeof(int));
	*local = 0;
	*nonLocal = 1;

	pthread_create(&a[0], NULL, localAreaNetwork, (void *) (local));
	pthread_create(&a[1], NULL, nonLocalAreaNetwork, (void *) (nonLocal));
	pthread_join(a[0],NULL);
}

void * localAreaNetwork(void * arg)
{
	// int i=*((int*) arg);
	sckLocal = socket(AF_INET, SOCK_DGRAM, 0);
	char buffer[_LEN + _LEN];
	struct sockaddr_in aux;
	
	checkSocket(sckLocal);
	rcvLocalArea = setAddrInfors(INADDR_ANY, _LOCAL_PORT);
	sendLocalArea = setCharAddrInfors(_LOCAL_IP_ADDRESS, _SERVER_LOCAL_PORT);
	bindPort(sckLocal, rcvLocalArea, _LOCAL_PORT);

	while (true)
	{
		memset(buffer, 0x0, _LEN);
		localPackageListener(buffer);	
	}
	close(sckLocal);
}

void * nonLocalAreaNetwork(void * arg)
{
	// int i=*((int*) arg);
	sckNonLocal = socket(AF_INET, SOCK_DGRAM, 0);
	char buffer[_LEN + _LEN];

	checkSocket(sckNonLocal);
	rcvNonLocalArea = setAddrInfors(INADDR_ANY, _NON_LOCAL_PORT);
	bindPort(sckNonLocal, rcvNonLocalArea, _NON_LOCAL_PORT);

	while (true)
	{
		memset(buffer, 0x0, _LEN);
		nonLocalPackageListener(buffer);	
	}
	close(sckNonLocal);
}

void checkSocket(int socket)
{
	if (socket == -1)
	{
		printf("[%s]: There was a problem creating the socket.\n", _MAIN_SERVER);
		exit(1);
	}
	else
		printf("[%s]: Socket was created successfully!\n", _MAIN_SERVER);
}

struct sockaddr_in setAddrInfors(unsigned int ipAddress, unsigned int port)
{
	struct sockaddr_in addr;
	addr.sin_family = AF_INET; 
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = htonl(ipAddress);
	memset(addr.sin_zero, 0x0, 8);	
	
	return addr;
}

struct sockaddr_in setCharAddrInfors(char * ipAddress, unsigned int port)
{
	struct sockaddr_in addr;
	addr.sin_family = AF_INET; 
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(ipAddress);
	memset(addr.sin_zero, 0x0, 8);	
	
	return addr;
}

void bindPort(int sck, struct sockaddr_in addr, int port)
{
	if (bind(sck, (struct sockaddr *) &addr, sizeof(addr)) == -1 )
	{	
		printf("[%s]: There was a problem opening the port...\n", _MAIN_SERVER);
		exit(1);
	}
	else
		printf("[%s]: Port %d was opened successfully! Listening...\n", _MAIN_SERVER, port);
}

void localPackageListener(char * buffer)
{
	int buffer_size;
	int sizeAddr = sizeof(rcvLocalArea);	

	if ((buffer_size = recvfrom(sckLocal, buffer, _LEN, 0, (struct sockaddr*)&rcvLocalArea, &sizeAddr)) <= 0)
        printf("[%s]: Recvfrom local host failed!\n", _MAIN_SERVER);
	else
	{
		printBuffer(buffer, buffer_size, _IS_LOCAL);

		char * bufferContent = getPackageContent(buffer);
		struct sockaddr_in hostDest = getHeaderDestAddr(buffer);

		int status = packageAnalyzer(hostDest, bufferContent, _IS_LOCAL);
		nonLocalPackageSender(bufferContent, hostDest);
	}
}

void nonLocalPackageListener(char * buffer)
{
	int buffer_size;
	int sizeAddr = sizeof(rcvNonLocalArea);

	if ((buffer_size = recvfrom(sckNonLocal,  buffer, _LEN+_LEN, 0, (struct sockaddr*)&rcvNonLocalArea, &sizeAddr)) <= 0)
        printf("[%s]: Recvfrom non-local host failed!\n", _MAIN_SERVER);
	else
	{
		printBuffer(buffer, buffer_size, _IS_NON_LOCAL);
		int status = packageAnalyzer(rcvNonLocalArea, buffer, _IS_NON_LOCAL);
		if (status == _OK)
			localPackageSender(putHeaderDestAddr(buffer, &rcvNonLocalArea));
	}
}

void localPackageSender(char * buffer)
{
	printTrace(rcvNonLocalArea, sendLocalArea);
//	struct sockaddr_in * test;
//	test = (struct sockaddr_in *) buffer;
//	printHost(test);

	if (sendto(sckLocal, (char*)buffer, sizeof(buffer), 0, (struct sockaddr*)&sendLocalArea, sizeof(sendLocalArea)) < 0)
        printf("[%s]: Sendto local host failed!\n", _MAIN_SERVER);
	else
		printf("[%s]: The package was forwarded to local host successfully!\n", _MAIN_SERVER);
}

void nonLocalPackageSender(char * buffer, struct sockaddr_in destAddr)
{
	printTrace(rcvLocalArea, destAddr);

	if (sendto(sckNonLocal, buffer, sizeof(buffer), 0, (struct sockaddr*)&destAddr, sizeof(destAddr)) < 0)
        printf("[%s]: Sendto non-local host failed!\n", _MAIN_SERVER);
	else
		printf("[%s]: The package was forwarded to non-local host successfully!\n", _MAIN_SERVER);
}

void printBuffer(char * buffer, int size, bool localNetHost)
{
	if (localNetHost)
		printf("[%s]: A message was received from local server. Buffer size: %d", _MAIN_SERVER, size);
	else
		printf("[%s]: A message was received from non-LOCAL server. Buffer size: %d\n", _MAIN_SERVER, size);
}

void printTrace(struct sockaddr_in src, struct sockaddr_in dest)
{
	char src_addr[_LEN];
	inet_ntop(AF_INET, &(src.sin_addr), src_addr, INET_ADDRSTRLEN);
	char dest_addr[_LEN];
	inet_ntop(AF_INET, &(dest.sin_addr), dest_addr, INET_ADDRSTRLEN);

	printf("[%s]: [TRACE] -> host[%s:%d] is sending a package to host[%s:%d]\n", _MAIN_SERVER, src_addr, htons(src.sin_port), dest_addr, htons(dest.sin_port));
}

char * getPackageContent(char * buffer)
{
	return &buffer[_HEADER_ADDR_SZ];
}

char * putHeaderDestAddr(char * buffer, struct sockaddr_in * destAddr)
{
	struct sockaddr_in * aux;
	char * newBuffer = (char *) malloc(sizeof(_HEADER_ADDR_SZ + sizeof(buffer)));

	aux = (struct sockaddr_in *) newBuffer;
	aux->sin_family = destAddr->sin_family;
	aux->sin_port = destAddr->sin_port;
	aux->sin_addr = destAddr->sin_addr;
	strcpy(aux->sin_zero, destAddr->sin_zero);

	char * content;
	content = &newBuffer[_HEADER_ADDR_SZ];
	strcpy(content, buffer); // analisar se todo o conteudo esta sendo passado
	return newBuffer;
}

struct sockaddr_in getHeaderDestAddr(char * buffer)
{
	struct sockaddr_in * destAddr = (struct sockaddr_in *) buffer;
	return setAddrInfors(destAddr->sin_addr.s_addr, htons(destAddr->sin_port));
}

void printHost(struct sockaddr_in * host)
{
	char node_addr[_LEN];
	inet_ntop(AF_INET, &(host->sin_addr), node_addr, INET_ADDRSTRLEN);

	printf("Host: [%s:%s]\n", node_addr, htons(host->sin_port));
}

