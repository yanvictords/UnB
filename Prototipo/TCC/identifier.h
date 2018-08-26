#include "packages.h"
#include "feedback.h"

//===== PROTOCOLS
#define _DNS 1
#define _NTP 2
#define _SNMP 3
#define _SSDP 4
#define _UNKNOWN_PROTOCOL 0

//===== MODULE
#define _MODULE_IDENTIFIER "IDENTIFIER"

int protocolIdentifier(unsigned short port);
int identifyByPort(int port);
