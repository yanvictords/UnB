#include "../../include/essential.h"
#include "../../include/Api/utils.h"
#include "../../include/Api/socket.h"

// ------------ MOUNT's

struct sockaddr_in mountAddr (unsigned long ipAddr, unsigned int port) {
	struct sockaddr_in addr;
	addr.sin_addr.s_addr = ipAddr;
	addr.sin_port = port;
	addr.sin_family = AF_INET;
	memset(addr.sin_zero, 0x0, 8);

	return addr;
}

struct sockaddr_in mountCharAddrInfors (char * ipAddress, unsigned int port) {
	struct sockaddr_in addr;
	addr.sin_family = AF_INET; 
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(ipAddress);
	memset(addr.sin_zero, 0x0, 8);	
	
	return addr;
}

// ------------ GET's

char * getPayload (char * buffer) {
	return (char *) &buffer[_SIZE_OF_ETH + _SIZE_OF_IP + _SIZE_OF_UDP];
}

unsigned int getSPortFromBuffer (char * buffer) {
	struct udphdr *udp_header = (struct udphdr *)&buffer[_SIZE_OF_ETH + _SIZE_OF_IP];
	return udp_header->uh_sport;
}

unsigned int getDPortFromBuffer (char * buffer) {
	struct udphdr *udp_header = (struct udphdr *)&buffer[_SIZE_OF_ETH + _SIZE_OF_IP];
	return udp_header->uh_dport;
}

struct in_addr getSAddrFromBuffer (char * buffer) {
	struct sockaddr_in source;
	struct iphdr *ip_packet = (struct iphdr *)&buffer[_SIZE_OF_ETH];

	memset(&source, 0, sizeof(source));
	source.sin_addr.s_addr = ip_packet->saddr;

	return source.sin_addr;
}

struct in_addr getDAddrFromBuffer (char * buffer) {
	struct sockaddr_in destiny;
	struct iphdr *ip_packet = (struct iphdr *)&buffer[_SIZE_OF_ETH];

	memset(&destiny, 0, sizeof(destiny));
	destiny.sin_addr.s_addr = ip_packet->daddr;	
	return destiny.sin_addr;
}

char * getIpByInterfaceName (int sck, char * interface) {
	char *ip;
	struct ifreq ifr;
	int ipSize;

	ifr.ifr_addr.sa_family = AF_INET;
	strncpy(ifr.ifr_name, interface, IFNAMSIZ-1);
	ioctl(sck, SIOCGIFADDR, &ifr);
	
	ipSize = sizeof(inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr)); 	
	ip = (char *) malloc(ipSize);
	strcpy(ip, (char *) inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));
	return ip;
}

// ------------ PRINT's

void printBuffer (char * buffer, int size, bool localNetHost) {
	printf("\n");
	if (localNetHost) {
		printf("[%s]: A new message was received from local server. Buffer size: %d", _API_SERVER, size);
	}	else {
		printf("[%s]: A new message was received from non-LOCAL server. Buffer size: %d\n", _API_SERVER, size);
	}
}

void printHost (struct sockaddr_in * host) {
	char node_addr[4096];
	inet_ntop(AF_INET, &(host->sin_addr), node_addr, INET_ADDRSTRLEN);

	printf("\nPrint Host: [%s:%d]\n", node_addr, htons(host->sin_port));
}

void printTrace (struct sockaddr_in src, struct sockaddr_in dest) {
	char src_addr[_BUFFER_SIZE];
	inet_ntop(AF_INET, &(src.sin_addr), src_addr, INET_ADDRSTRLEN);
	char dest_addr[_BUFFER_SIZE];
	inet_ntop(AF_INET, &(dest.sin_addr), dest_addr, INET_ADDRSTRLEN);

	printf("[%s]: [TRACE] -> host[%s:%d] is sending a package to host[%s:%d]\n", 
		_API_SERVER, src_addr, htons(src.sin_port), dest_addr, htons(dest.sin_port));
}

void printAllPacketContent (char * buffer) {
	struct ethhdr *eth = (struct ethhdr *)buffer;
	struct iphdr *ip_packet = (struct iphdr *)&buffer[_SIZE_OF_ETH];
	struct udphdr *udp_header = (struct udphdr *)&buffer[_SIZE_OF_ETH + _SIZE_OF_UDP];

	char * buf;
	buf = (char *) &buffer[_SIZE_OF_ETH + _SIZE_OF_IP + _SIZE_OF_UDP];

	printf("\n--------------------------------------------\n");
	printf("[%s]:", _API_SERVER);
	printf("\n---------\n");
	printf( "Ethernet Header\n");
	printf( "|-Destination Address    : %.2X-%.2X-%.2X-%.2X-%.2X-%.2X \n", eth->h_dest[0] , eth->h_dest[1] , eth->h_dest[2] , eth->h_dest[3] , eth->h_dest[4] , eth->h_dest[5] );
	printf( "|-Source Address         : %.2X-%.2X-%.2X-%.2X-%.2X-%.2X \n", eth->h_source[0] , eth->h_source[1] , eth->h_source[2] , eth->h_source[3] , eth->h_source[4] , eth->h_source[5] );
	printf( "|-Protocol               : %u \n",(unsigned short)eth->h_proto);
	
	printf("\nIp Header\n");
	printf("|-Header checksum        : %d\n", ntohs(ip_packet->check));
	printf("|-Source IP Address      : %s\n", (char *)inet_ntoa(getSAddrFromBuffer(buffer)));
	printf("|-Destination ip Address : %s\n", (char *)inet_ntoa(getDAddrFromBuffer(buffer)));
	printf("|-Packet Size (bytes)    : %d\n",ntohs(ip_packet->tot_len));
	printf("|-Protocol               : %u\n", (unsigned) ip_packet->protocol);
	printf("|-Identification         : %d\n", ntohs(ip_packet->id));

	printf("\nUDP Header\n");
	printf("|-Port - Source          : %d\n", ntohs(getSPortFromBuffer(buffer)));
	printf("|-Port - Destiny         : %d\n", ntohs(getDPortFromBuffer(buffer)));
	printf("|-Checksum               : %d\n", ntohs(udp_header->uh_sum)); 
	
	printf("--------------------------------------------\n");
}