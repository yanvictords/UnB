#include "../include/identifier.h"

int protocolIdentifier(unsigned short port)
{
	int protocol = identifyByPort(htons(port));
	printProtocolName(_MODULE_IDENTIFIER, protocol);
	return protocol;
}

int identifyByPort(int port)
{
	switch (port)	
	{
		case 53:
			return _DNS;
		case 123:
			return _NTP;		
		case 161:
			return _SNMP;
		case 1900:
			return _SSDP;
//		default:  // just for test
//			return _DNS;
	}
	return _UNKNOWN_PROTOCOL;
}
