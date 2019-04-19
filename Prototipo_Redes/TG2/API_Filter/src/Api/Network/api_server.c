#include "../../../include/Api/Network/api_server.h"

#include "../../../include/Api/Network/utils.h"
#include "../../../include/Api/Network/socket.h"
#include "../../../include/DetectorTool/detectorTool.h"

void apiServer()
{
	// getNetworkConfInformations();
	_running = true;
	startApiServer();
}

void startApiServer()
{
	char buffer[_BUFFER_SIZE];
	long bufferSize;

	printf("[%s]: Starting Api server...\n", _API_SERVER);
	_sckRaw = createSocket(_RAW_ETH);
	_sckUdp = createSocket(_UDP);

	// setEthHeaderInSocket(_sckRaw, "eth0");

	_sourceAddr = mountAddr(INADDR_ANY, htons(9000));
	bindPort(_sckUdp, _sourceAddr);

	while(_running)
	{
		memset(buffer, 0x0, _BUFFER_SIZE);
		if(bufferSize = listenToPackages(_sckRaw, buffer, _BUFFER_SIZE, &_destinyAddr) > 0)
		{	 
			if(shouldAnalyzePackage(_sckRaw, buffer))
			{
				printAllPacketContent(buffer);	
	
				_destinyAddr = mountAddr(getDAddrFromBuffer(buffer).s_addr, getDPortFromBuffer(buffer));
				detectorTool(_destinyAddr, getPayload(buffer), ifLanIpAddress(inet_ntoa(getSAddrFromBuffer(buffer))));
				// sendPackage(_sckUdp, getPayload(buffer), _destinyAddr);
			}
		}
	}
}

_Bool shouldAnalyzePackage(int sck, char * buffer)
{
	return  (!ifLocalIpAddress(sck, buffer) && 
			ifIsUdpProtocol(buffer));
}
