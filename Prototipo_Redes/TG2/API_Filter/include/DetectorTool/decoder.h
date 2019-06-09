#include "../../include/essential.h"

//===== PACKAGES
#define _REQUEST 1
#define _RESPONSE -1
#define _UNKNOWN_QUERY_TYPE 0

//===== LIST OF QUERY TYPES BY PROTOCOLS
#define _DNS_REQUEST 0
#define _DNS_RESPONSE 1

#define _1BIT 1
#define _4BITS 4

//===== MODULE
#define _MODULE_DECODER "DECODER"

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

long long decoder (int protocol,  char * buffer);
int getDnsQueryType(char * buffer);
int getNtpQueryType (char * buffer);
int getSnmpQueryType (char * buffer);
int getSsdpQueryType (char * buffer);
