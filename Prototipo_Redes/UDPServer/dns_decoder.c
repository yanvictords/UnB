#include "dns_decoder.h"

int pkgAnalyzer(struct sockaddr_in addr, char * buffer)
{
	char node_addr[_LEN];
	inet_ntop(AF_INET, &(addr.sin_addr), node_addr, INET_ADDRSTRLEN);

	printf("\n\n***Analyzer Log*** \n");
	printf("***Log: Analyzing the pkg from node '%s', by port: %d \n", node_addr, htons(addr.sin_port));
	if(!isDnsServer(addr))
		return 0;

	bool isHost = isHostServer(addr);
	int queryResponse = queryOrResponse(buffer);
	int counter;

	if(queryResponse == 1 && !isHost)
	{
		printf("***Log: Another server is responding a question to the host server.\n");
		counter = countersList(addr.sin_addr, -1);
		if(counter < 0)
		{
			printf("***Log: ALERT!!! Maybe the node '%s' can be a reflector!... Pkg Counter: %d\n", node_addr, counter);
		}
		return -1;		
	}

	if(queryResponse == 0 && isHost)
	{
		printf("***Log: The host server is asking a question (query).\n");
		countersList(addr.sin_addr, 1);
		return 1;
	}

	if(queryResponse == 1 && isHost)
	{
		printf("***Log: The host is responding a question (response).\n");
		counter = countersList(addr.sin_addr, -1);
		if(counter < 0)
		{
			printf("***Log: WARNING! The host server responded a DNS pkg without a previous question.\n");
		}
		return 2;
	}

	if(queryResponse == 0 && !isHost)
	{
		printf("***Log: Another server is asking a question to the host server (query).\n");
		countersList(addr.sin_addr, 1);
		return 3;
	}
}

// returns is a DNS server
bool isDnsServer(struct sockaddr_in addr)
{
	bool dns = (bool) (htons(addr.sin_port) == _DNS_PORT);
	dns=true;
	if(dns)
		printf("***Log: The pkg is a DNS package. ");
	else
		printf("***Log: This pkg doesn't belong to DNS protocol.\n");	

	return dns;
}

// returns if is the principal server (victim)
bool isHostServer(struct sockaddr_in addr)
{
	char server[_LEN];
	inet_ntop(AF_INET, &(addr.sin_addr), server, INET_ADDRSTRLEN);
	return (bool) !strcmp(server, _FINAL_SERVER);
}

// returns if is a query or response
int queryOrResponse(char * buffer)
{
	struct DNS_HEADER *dns = NULL;
    dns = (struct DNS_HEADER*) buffer;

	if(((int) dns->qr) == 1)
		printf("Type: RESPONSE.\n");
	else
		printf("Type: QUERY.\n");
	return (int) dns->qr;
}

// Identify if is a query or response and dec/add +1 in the counter - returns the counter value
int countersList(struct in_addr sin_addr, int incr)
{
	unsigned long sAddr = sin_addr.s_addr;

	// if there aren't pendant queries from both sides
	if(root == NULL) 
	{
		struct COUNT_ADDR * newRoot = (struct COUNT_ADDR*) malloc(sizeof(struct COUNT_ADDR*));
		newRoot->next = NULL;
		newRoot->count += incr;
		newRoot->sin_addr.s_addr = sAddr;
		root = newRoot;
		return root->count;
	}

	struct COUNT_ADDR * listAux, *antec;
	listAux = root;	
	antec = NULL;
	while(listAux!=NULL)
	{
		if(listAux->sin_addr.s_addr == sAddr)
		{
			listAux->count += incr;
			// If antec, do a swap to bring the node until first position
			if(antec != NULL)
			{
				antec->next = listAux->next;
				listAux->next = root;
				root = listAux;
				}
			return root->count;
		}
		antec = listAux;
		listAux=listAux->next;
	}

	struct COUNT_ADDR * newCount = (struct COUNT_ADDR*) malloc(sizeof(struct COUNT_ADDR*));
	newCount->next = root;
	root = newCount;
	newCount->sin_addr.s_addr = sAddr;
	return newCount->count += incr;
}

// prints all counters from the servers
void printAllCounters()
{
	char aux[_LEN];
	int size=0;
	printf("\n***Listing All Counters***\n");
	struct COUNT_ADDR * listAux;
	listAux = root;
	while(listAux!=NULL){
		inet_ntop(AF_INET, &(listAux->sin_addr), aux, _LEN);
		printf("IP: %s - Counter: %d\n", aux, listAux->count); 
		listAux=listAux->next;
		size++;
	}
	printf("*** Size: %d\n***End Counters***\n\n", size);
}
