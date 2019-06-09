#include "../../include/essential.h"

//===== STATUS
#define _ANOMALOUS_OP -1
#define _NORMAL_OP 1

//===== MODULE
#define _MODULE_RECORD "RECORD"

struct COUNT_ADDR
{
	long long count;
	struct in_addr sin_addr;
	struct COUNT_ADDR * next;
} *_pDns, *_pNtp, *_pSnmp, *_pSsdp;

long long record (struct in_addr sin_addr, long long operation, int protocol);
bool mustKeepHostOnTheList (struct COUNT_ADDR * listAux);
void setProtocolRoot (int protocol, struct COUNT_ADDR * root);
struct COUNT_ADDR * getProtocolRoot (int protocol);
struct COUNT_ADDR * create_node (struct COUNT_ADDR * next, unsigned long addr);
void printAllCounters (int protocol);

