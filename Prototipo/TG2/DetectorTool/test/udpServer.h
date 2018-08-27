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
#define _MAIN_SERV_PORT 80
#define _REAL_ADDR "8.8.8.8"
#define _REAL_SERV_PORT 53

#define _HEADER_ADDR_SZ sizeof(struct sockaddr)
#define _LEN 65536
#define _1BIT 1
#define _4BITS 4

struct sockaddr_in mainServerSend;
struct sockaddr_in mainServerListen;
struct sockaddr_in * realServerAddress;

typedef uint16_t byte_2;
struct DNS_HEADER
{
    byte_2 id;
    unsigned char rd:	_1BIT; 
    unsigned char opcode:	_4BITS; 
    unsigned char aa:	_1BIT; 
    unsigned char tc:	_1BIT;
    unsigned char qr:	_1BIT; 
    unsigned char ra:	_1BIT; 
    unsigned char z:	_1BIT; 
    unsigned char rcode:	_4BITS;
    unsigned char cd:	_1BIT; 
    unsigned char ad:	_1BIT; 
    byte_2 qd_count; 
    byte_2 an_count; 
    byte_2 ns_count; 
    byte_2 ar_count; 
};

void startServer();
void checkSocket(int sck_server);
void bindPort(int sck, struct sockaddr_in addr, int port);
void * toListen(void * args);
void * toSend(void * args);
