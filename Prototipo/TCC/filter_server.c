#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <inttypes.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "pthread.h"

#define _FINAL_SERVER "127.0.0.1"
#define _LEN 65536
#define _DNS_PORT 53

struct sockaddr_in sckLocal;
struct sockaddr_in sckNonLocal;

void checkSocket(int socket)
{
	if(socket == -1)
	{
		printf("There was a problem creating the socket.\n");
		exit(1);
	}
	else
		printf("Socket was created successfully!\n");
}

void * localAreaNetwork(void * arg)
{
	int i=*((int*) arg);
	int sck = socket(AF_INET, SOCK_DGRAM, 0);
	int tam_buff;
	char buffer[_LEN];
	
	checkSocket(sck);

}

void * nonLocalAreaNetwork(void * arg)
{
	int i=*((int*) arg);
	int sck = socket(AF_INET, SOCK_DGRAM, 0);
	int tam_buff;
	char buffer[_LEN];

	checkSocket(sck);
}

void init_server()
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

int main()
{
	init_server();
	return 0;
}
