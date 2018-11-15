#include "../essential.h"
#include "identifier.h"

//===== STATUS
#define _ANOMALOUS_OP -1
#define _NORMAL_OP 1

//===== MODULE
#define _MODULE_RECORD "RECORD"

//===== BORDERS
#define _LOW_LIMIT -5

struct COUNT_ADDR
{
	int count;
	struct in_addr sin_addr;
	struct COUNT_ADDR * next;
} *_pDns, *_pNtp, *_pSnmp, *_pSsdp;

int record(struct in_addr sin_addr, int operation, int protocol);
int updateCountersList(struct in_addr sin_addr, int operation, int protocol);
bool mustKeepHostOnTheList(struct COUNT_ADDR * listAux);
void setProtocolRoot(int protocol, struct COUNT_ADDR * root);
struct COUNT_ADDR * getProtocolRoot(int protocol);
struct COUNT_ADDR * create_node(struct COUNT_ADDR * next, unsigned long addr);
void printAllCounters(int protocol);

