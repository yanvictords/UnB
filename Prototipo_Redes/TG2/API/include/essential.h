#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

#include <arpa/inet.h>
#include <net/if.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <netinet/udp.h>
#include <sys/cdefs.h>
#include <sys/ioctl.h>

//===== CONFIGURATION FILE
#define _CONFIG_FILE "API.conf"
#define _HIGH_LIMIT 30

//===== API.conf
char _PROXY_IP[100];
int _PROXY_PORT;
char _BLACKLIST_FILE[100];
long long _LOW_LIMIT;
int _DEBUG_MODE;

