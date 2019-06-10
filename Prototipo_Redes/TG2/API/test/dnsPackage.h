// Code logic inspired by Author : Silver Moon (m00n.silv3r@gmail.com)
//Dated : 29/4/2009
//CÓDIGO ALTERADO POR YAN VICTOR DOS SANTOS PARA FINS DE TESTES
#include "essential.h"

typedef uint8_t u1;
typedef uint16_t u2;
typedef uint32_t u4;
typedef uint64_t u8;

#define T_A 1 //Ipv4 address
#define T_NS 2 //Nameserver
#define T_CNAME 5 // canonical name
#define T_SOA 6 /* start of authority zone */
#define T_PTR 12 /* domain name pointer */
#define T_MX 15 //Mail server

#define _QUERY 0 
#define _RESPONSE 1

struct DNS_H
{
    unsigned short id; 
 
    unsigned char rd :1; 
    unsigned char opcode :4;
    unsigned char aa :1; 
    unsigned char tc :1; 
    unsigned char qr :1; 
 
    unsigned char ra :1; 
    unsigned char z :1; 
    unsigned char rcode :4;
    unsigned char cd :1; 
    unsigned char ad :1; 
 
    unsigned short q_count; 
    unsigned short ans_count;
    unsigned short auth_count;
    unsigned short add_count; 
};
 
struct QUESTION
{
    unsigned short qtype;
    unsigned short qclass;
};
 
void mountDnsPackage(unsigned char queryOrResponse, char * buf, char * host);
