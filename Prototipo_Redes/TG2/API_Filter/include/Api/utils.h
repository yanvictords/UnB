//===== MODULE
#define _API_SERVER "SERVER"

//===== SIZEOF's
#define _SIZE_OF_ETH sizeof(struct ethhdr)
#define _SIZE_OF_IP sizeof(struct iphdr)
#define _SIZE_OF_UDP sizeof(struct udphdr)

#define _BUFFER_SIZE 65536
#define _UDP_PROTOCOL 17

struct sockaddr_in * mountAddr (unsigned long ipAddr, unsigned int port);
struct sockaddr_in mountCharAddrInfors (char * ipAddress, unsigned int port);
char * getPayload (char * buffer);
unsigned int getSPortFromBuffer (char * buffer);
unsigned int getDPortFromBuffer (char * buffer);
struct in_addr getSAddrFromBuffer (char * buffer);
struct in_addr getDAddrFromBuffer (char * buffer);
char * getIpByInterfaceName (int sck, char * interface);
void printBuffer (char * buffer, int size, bool localNetHost);
void printHost (struct sockaddr_in * host);
void printTrace (struct sockaddr_in src, struct sockaddr_in dest);
void printAllPacketContent (char * buffer);