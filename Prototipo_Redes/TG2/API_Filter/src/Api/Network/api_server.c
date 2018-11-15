#include "../../../include/Api/Network/api_server.h"

void apiServer()
{
	getNetworkConfInformations();
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
	_sckLocal =		createSocket(_UDP);
	char buffer[_BUFFER_SIZE + _BUFFER_SIZE];
	struct sockaddr_in aux;
	
	rcvLocalArea =		setAddrInfors(INADDR_ANY, _local_interface_port);
	sendLocalArea =		setCharAddrInfors(_LOCAL_IP_ADDRESS, _SERVER_LOCAL_PORT);
	bindPort(_sckLocal, rcvLocalArea);

	while (true)
	{
		memset(buffer, 0x0, _BUFFER_SIZE);
		localPackageListener(buffer);	
	}
	close(_sckLocal);
}

void * nonLocalAreaNetwork(void * arg)
{
	_sckNonLocal =		createSocket(_UDP);
	char buffer[_BUFFER_SIZE + _BUFFER_SIZE];

	rcvNonLocalArea =		setAddrInfors(INADDR_ANY, _non_local_interface_port);
	bindPort(_sckNonLocal, rcvNonLocalArea);

	while (true)
	{
		memset(buffer, 0x0, _BUFFER_SIZE);
		nonLocalPackageListener(buffer);	
	}
	close(_sckNonLocal);
}

void localPackageListener(char * buffer)
{
	int buffer_size;
	int sizeAddr = sizeof(rcvLocalArea);	

	if ((buffer_size =		rcvPackage(_sckLocal, &rcvLocalArea, buffer, _BUFFER_SIZE)) <= 0)
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

	if ((buffer_size =		rcvPackage(_sckNonLocal, &rcvNonLocalArea, buffer, _BUFFER_SIZE+_BUFFER_SIZE)) <= 0)
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

	if (sendPackage(_sckLocal, &sendLocalArea, buffer, buffer_size) < 0)
        printf("[%s]: Sendto local host failed!\n", _API_SERVER);
	else
		printf("[%s]: The package was successfully forwarded to local host!\n", _API_SERVER);
}

void nonLocalPackageSender(char * buffer, int buffer_size, struct sockaddr_in destAddr)
{
	printTrace(rcvLocalArea, destAddr);

	if (sendPackage(_sckNonLocal, &destAddr, buffer, buffer_size) < 0)
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

void getNetworkConfInformations()
{
	FILE *networkConf;
	
	printf("[%s]: ### Reading the networking settings... ###\n", _API_SERVER);

	if(!(networkConf = fopen(_NETWORK_CONF_FILE, "r+")))
	{
		printf("[%s]: File %s was not found!\n", _API_SERVER, _NETWORK_CONF_FILE);
		generateNetworkConfFile(networkConf);
	}
	else
	{
		char lanPort[6];
		char nonLanPort[6];

		fscanf(networkConf, "######## Network Settings ########\n@LOCAL_interface:\nport: %s\n\n@NONLOCAL_interface:\nport: %s\n", lanPort, nonLanPort);

		_local_interface_port = atoi(lanPort);
		_non_local_interface_port = atoi(nonLanPort);

		fclose(networkConf);

		if (invalidPort(_local_interface_port) || invalidPort(_non_local_interface_port))
			exit(1);
	}
}

void generateNetworkConfFile(FILE * networkConf)
{
	networkConf = fopen(_NETWORK_CONF_FILE, "w+");

	printf("\n[%s]: ### Generating the Networking Settings... ###\n", _API_SERVER);

	do {
		printf("[%s]: Local Port: ", _API_SERVER);
		scanf("%d", &_local_interface_port);
	} while ( invalidPort(_local_interface_port) );

	do {
		printf("[%s]: Non-Local Port: ", _API_SERVER);
		scanf("%d", &_non_local_interface_port);
	} while ( invalidPort(_non_local_interface_port) );

	fprintf(networkConf, "######## Network Settings ########\n@LOCAL_interface:\nport: %d\n\n@NONLOCAL_interface:\nport: %d\n", _local_interface_port, _non_local_interface_port);
	
	fclose(networkConf);
}

bool invalidPort(int port) 
{
	bool isInvalid = (port <= 0 || port > 65535);
	
	if (isInvalid)
		printf("[%s]: [ERROR] The port %d is out of range! Try another port...\n", _API_SERVER, port);

	return isInvalid;
}