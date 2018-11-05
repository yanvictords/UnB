#include "../../../include/Api/Network/api_server.h"

void apiServer()
{
	startApiServer();
}

void startApiServer()
{
	printf("[%s]: Starting Api server...\n", _API_SERVER);
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

// ----- Main Functions Below

void * localAreaNetwork(void * arg)
{
	sckLocal =		createSocket(_UDP);
	char buffer[_BUFFER_SIZE + _BUFFER_SIZE];
	struct sockaddr_in aux;
	
	rcvLocalArea =		setAddrInfors(INADDR_ANY, _LOCAL_PORT);
	sendLocalArea =		setCharAddrInfors(_LOCAL_IP_ADDRESS, _SERVER_LOCAL_PORT);
	bindPort(sckLocal, rcvLocalArea);

	while (true)
	{
		memset(buffer, 0x0, _BUFFER_SIZE);
		localPackageListener(buffer);	
	}
	close(sckLocal);
}

void * nonLocalAreaNetwork(void * arg)
{
	sckNonLocal =		createSocket(_UDP);
	char buffer[_BUFFER_SIZE + _BUFFER_SIZE];

	rcvNonLocalArea =		setAddrInfors(INADDR_ANY, _NON_LOCAL_PORT);
	bindPort(sckNonLocal, rcvNonLocalArea);

	while (true)
	{
		memset(buffer, 0x0, _BUFFER_SIZE);
		nonLocalPackageListener(buffer);	
	}
	close(sckNonLocal);
}

void localPackageListener(char * buffer)
{
	int buffer_size;
	int sizeAddr = sizeof(rcvLocalArea);	

	if ((buffer_size =		rcvPackage(sckLocal, &rcvLocalArea, buffer, _BUFFER_SIZE)) <= 0)
		printf("[%s]: Recvfrom local host failed!\n", _API_SERVER);
	else
	{
		printBuffer(buffer, buffer_size, _IS_LOCAL);

		char * bufferContent = getPackageContent(buffer);
	
		if(buffer_size > _HEADER_ADDR_SZ)
			buffer_size -= _HEADER_ADDR_SZ;

		struct sockaddr_in hostDest = getHeaderDestAddr(buffer);
		printHost(&hostDest);

		int status =		detectorTool(hostDest, bufferContent, _IS_LOCAL);
		nonLocalPackageSender(bufferContent, buffer_size, hostDest);
	}
}

void nonLocalPackageListener(char * buffer)
{
	int buffer_size;
	int sizeAddr = sizeof(rcvNonLocalArea);

	if ((buffer_size =		rcvPackage(sckNonLocal, &rcvNonLocalArea, buffer, _BUFFER_SIZE+_BUFFER_SIZE)) <= 0)
	    printf("[%s]: Recvfrom non-local host failed!\n", _API_SERVER);
	else
	{
		printBuffer(buffer, buffer_size, _IS_NON_LOCAL);
		
		buffer_size += _HEADER_ADDR_SZ;

		int status =		detectorTool(rcvNonLocalArea, buffer, _IS_NON_LOCAL);
		if (status == _OK)
			localPackageSender(putHeaderDestAddr(buffer, &rcvNonLocalArea), buffer_size);
		else
			printf("[%s]: The package was dropped.\n", _API_SERVER);
	}
}

void localPackageSender(char * buffer, int buffer_size)
{
	printTrace(rcvNonLocalArea, sendLocalArea);

	if (sendPackage(sckLocal, &sendLocalArea, buffer, buffer_size) < 0)
        printf("[%s]: Sendto local host failed!\n", _API_SERVER);
	else
		printf("[%s]: The package was successfully forwarded to local host!\n", _API_SERVER);
}

void nonLocalPackageSender(char * buffer, int buffer_size, struct sockaddr_in destAddr)
{
	printTrace(rcvLocalArea, destAddr);

	if (sendPackage(sckNonLocal, &destAddr, buffer, buffer_size) < 0)
        printf("[%s]: Sendto non-local host failed!\n", _API_SERVER);
	else
		printf("[%s]: The package was successfully forwarded to non-local host!\n", _API_SERVER);
}

// ----- Auxiliar Functions Below

void printBuffer(char * buffer, int size, bool localNetHost)
{
	printf("\n");
	if (localNetHost)
		printf("[%s]: A new message was received from local server. Buffer size: %d", _API_SERVER, size);
	else
		printf("[%s]: A new message was received from non-LOCAL server. Buffer size: %d\n", _API_SERVER, size);
}

void printTrace(struct sockaddr_in src, struct sockaddr_in dest)
{
	char src_addr[_BUFFER_SIZE];
	inet_ntop(AF_INET, &(src.sin_addr), src_addr, INET_ADDRSTRLEN);
	char dest_addr[_BUFFER_SIZE];
	inet_ntop(AF_INET, &(dest.sin_addr), dest_addr, INET_ADDRSTRLEN);

	printf("[%s]: [TRACE] -> host[%s:%d] is sending a package to host[%s:%d]\n", _API_SERVER, src_addr, htons(src.sin_port), dest_addr, htons(dest.sin_port));
}

char * getPackageContent(char * buffer)
{
	return &buffer[_HEADER_ADDR_SZ];
}

char * putHeaderDestAddr(char * buffer, struct sockaddr_in * destAddr)
{
	struct sockaddr_in * aux;
	char * newBuffer = (char *) &buffer[_HEADER_ADDR_SZ];
	strcpy(newBuffer, buffer);	

	aux = (struct sockaddr_in *) buffer;
	aux->sin_family = destAddr->sin_family;
	aux->sin_port = destAddr->sin_port;
	aux->sin_addr = destAddr->sin_addr;
	strcpy(aux->sin_zero, destAddr->sin_zero);

	return buffer;
}

struct sockaddr_in getHeaderDestAddr(char * buffer)
{
	struct sockaddr_in * destAddr = (struct sockaddr_in *) buffer;
	return *destAddr;
}

void printHost(struct sockaddr_in * host)
{
	char node_addr[_BUFFER_SIZE];
	inet_ntop(AF_INET, &(host->sin_addr), node_addr, INET_ADDRSTRLEN);

	printf("\nPrint Host: [%s:%d]\n", node_addr, htons(host->sin_port));
}

