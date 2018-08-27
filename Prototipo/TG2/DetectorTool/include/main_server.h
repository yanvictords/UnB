#include <pthread.h>
#include "packages.h"
#include "analyzer.h"
#include "../test/dnsPackage.h"
#include <time.h>

#define _LEN 65536
#define _IS_LOCAL true
#define _IS_NON_LOCAL false

#define _LOCAL_IP_ADDRESS "127.0.0.1"
#define _SERVER_LOCAL_PORT 3000
#define _LOCAL_PORT 2000
#define _NON_LOCAL_PORT 80

//===== MODULE
#define _MAIN_SERVER "MAIN_SERVER"

//===== VARIABLES
#define _HEADER_ADDR_SZ sizeof(struct sockaddr)

struct sockaddr_in rcvLocalArea;
struct sockaddr_in rcvNonLocalArea;
struct sockaddr_in sendLocalArea;
struct sockaddr_in sendNonLocalArea;

int sckLocal;
int sckNonLocal;

void startServer();
void * localAreaNetwork(void * arg);
void * nonLocalAreaNetwork(void * arg);
void checkSocket(int socket);
struct sockaddr_in setAddrInfors(unsigned int ipAddress, unsigned int port);
struct sockaddr_in setCharAddrInfors(char * ipAddress, unsigned int port);
void bindPort(int sck, struct sockaddr_in addr, int port);
void localPackageListener(char * buffer);
void nonLocalPackageListener(char * buffer);
void localPackageSender(char * buffer);
void nonLocalPackageSender(char * buffer, struct sockaddr_in destAddr);
void printBuffer(char * buffer, int size, bool localNetHost);
void printTrace(struct sockaddr_in src, struct sockaddr_in dest);
char * getPackageContent(char * buffer);
char * putHeaderDestAddr(char * buffer, struct sockaddr_in * destAddr);
struct sockaddr_in getHeaderDestAddr(char * buffer);
void printHost(struct sockaddr_in * host);
