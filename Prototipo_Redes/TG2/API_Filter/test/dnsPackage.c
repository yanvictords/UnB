// Code logic inspired by Author : Silver Moon (m00n.silv3r@gmail.com)

#include "dnsPackage.h"

void mountDnsPackage(unsigned char queryOrResponse, char * buf, char * host)
{
	char *name;
    struct DNS_H *dns = NULL;
    struct QUESTION *info = NULL;
    dns = (struct DNS_H *) buf;
    dns->id = (unsigned short) htons(getpid());
    dns->rd = 1; 
    dns->tc = 0; 
    dns->aa = 0; 

    dns->opcode = 0; 
    dns->qr = queryOrResponse; 
    dns->rcode = 0;
    dns->cd = 0;
    dns->ad = 0;
    dns->z = 0;
    dns->ra = 0;
    dns->q_count = htons(1); 
    dns->ans_count = 0;
    dns->auth_count = 0;
    dns->add_count = 0;
    name =(unsigned char*)&buf[sizeof(struct DNS_H)];

    int lock = 0 , i;
    strcat((char*)host,".");
     
    for(i = 0 ; i < strlen((char*)host) ; i++) 
    {
        if(host[i]=='.') 
        {
            *name++ = i-lock;
            for(;lock<i;lock++) 
            {
                *name++=host[lock];
            }
            lock++;
        }
    }
    *name++='\0';

    info =(struct QUESTION*)&buf[sizeof(struct DNS_H) + (strlen((const char*)name) + 1)]; 
    info->qtype = htons( T_A ); 
    info->qclass = htons(1);
}

