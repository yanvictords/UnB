//===== MODULE
#define _SOCKET "SOCKET"

#define _TCP 0
#define _UDP 1
#define _RAW_ETH 2

#define _API_INTERFACE "wlp2s0"

int createSocket (int type);
void bindPort (int sck, struct sockaddr_in addr);
int connectSocket (int socket,	struct sockaddr_in server);
void setEthHeaderInSocket (int socket);
ssize_t listenToPackages (int type, int socket, char *buffer, int bufferSize, struct sockaddr_in * source);
ssize_t sendPackage (int type, int socket, char * buffer, struct sockaddr_in destiny);
void closeSocket (int * socket);