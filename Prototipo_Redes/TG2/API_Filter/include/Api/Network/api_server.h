#include "../../essential.h"

#include <stdbool.h>

#define _TCP 0
#define _UDP 1
#define _RAW 2

#define _BUFFER_SIZE 65536
#define _LOW_BUFFER_SIZE 4096

//===== MODULE
#define _API_SERVER "API_SERVER"

#define _API_INTERFACE "wlp2s0"

struct sockaddr_in _sourceAddr;
struct sockaddr_in _destinyAddr;
int _sckRaw;
int _sckUdp;
bool _running;

void apiServer();
void startApiServer();
_Bool shouldAnalyzePackage(int _sckRaw, char * buffer);
