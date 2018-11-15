#include <pthread.h>
#include <time.h>

#include "../../essential.h"
#include "socket.h"
#include "../../DetectorTool/detectorTool.h"

#define _TCP 0
#define _UDP 1
#define _RAW 2

#define _BUFFER_SIZE 65536
#define _IS_LOCAL true
#define _IS_NON_LOCAL false

#define _LOCAL_IP_ADDRESS "127.0.0.1"
#define _SERVER_LOCAL_PORT 3000
// #define _LOCAL_PORT 9000
// #define _NON_LOCAL_PORT 8000

//===== NETWORK CONFIGURATION FILE
#define _NETWORK_CONF_FILE "network.conf"

//===== MODULE
#define _API_SERVER "API_SERVER"

//===== VARIABLES
#define _HEADER_ADDR_SZ sizeof(struct sockaddr)

struct sockaddr_in rcvLocalArea;
struct sockaddr_in rcvNonLocalArea;
struct sockaddr_in sendLocalArea;
struct sockaddr_in sendNonLocalArea;

int _sckLocal;
int _sckNonLocal;

int _local_interface_port;
int _non_local_interface_port;

void apiServer();
void startApiServer();
void * localAreaNetwork(void * arg);
void * nonLocalAreaNetwork(void * arg);
void localPackageListener(char * buffer);
void nonLocalPackageListener(char * buffer);
void localPackageSender(char * buffer, int buffer_size);
void nonLocalPackageSender(char * buffer, int buffer_size, struct sockaddr_in destAddr);
void printBuffer(char * buffer, int size, bool localNetHost);
void printTrace(struct sockaddr_in src, struct sockaddr_in dest);
char * getPackageContent(char * buffer);
char * putHeaderDestAddr(char * buffer, struct sockaddr_in * destAddr);
struct sockaddr_in getHeaderDestAddr(char * buffer);
void printHost(struct sockaddr_in * host);
void getNetworkConfInformations();
void generateNetworkConfFile(FILE * networkConf);
bool invalidPort(int port);