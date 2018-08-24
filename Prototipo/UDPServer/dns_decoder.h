#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <inttypes.h>
#include <stdbool.h>

#define _1BIT 1
#define _4BITS 4
#define _FINAL_SERVER "127.0.0.1"
#define _LEN 65536
#define _DNS_PORT 53

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

struct COUNT_ADDR
{
	int count;
	struct in_addr sin_addr;
	struct COUNT_ADDR * next;
}*root;

int pkgAnalyzer(struct sockaddr_in addr, char * buffer);
bool isDnsServer(struct sockaddr_in addr);
bool isHostServer(struct sockaddr_in addr); // Verifica se é o servidor final
int queryOrResponse(char * buffer); // Define se eh resposta (1) ou pergunta (0)
int countersList(struct in_addr sin_addr, int incr);
void printAllCounters();
