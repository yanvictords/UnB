#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <inttypes.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <pthread.h>

#include "dnsPackage.h"

#define _LOCAL_PORT 3000

#define _MAIN_ADDR "127.0.0.1"
#define _MAIN_SERV_PORT 2000
#define _REAL_ADDR "8.8.4.4"
#define _REAL_SERV_PORT 53

#define _HEADER_ADDR_SZ sizeof(struct sockaddr)
#define _LEN 65500
#define _1BIT 1
#define _4BITS 4

struct sockaddr_in mainServerSend;
struct sockaddr_in mainServerListen;
struct sockaddr_in * realServerAddress;

int sck;

void startServer();
void checkSocket(int sck_server);
void bindPort(struct sockaddr_in addr, int port);
void * toListen(void * args);
void * toSend(void * args);
