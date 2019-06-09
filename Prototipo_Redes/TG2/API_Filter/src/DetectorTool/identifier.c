#include "../../include/DetectorTool/identifier.h"

#include "../../include/DetectorTool/ui.h"

int identifier (unsigned short port) {
	int protocol = identifyByPort(htons(port));
	printProtocolName(_MODULE_IDENTIFIER, protocol);

	return protocol;
}

int identifyByPort (int port) {
	switch (port)	{
		case _DNS_PORT:
			return _DNS;
		case _NTP_PORT: // TODO
			return _NTP;		
		case _SNMP_PORT: // TODO
			return _SNMP;
		case _SSDP_PORT: // TODO
			return _SSDP;
		default:
			return _UNKNOWN_PROTOCOL;
	}
}
