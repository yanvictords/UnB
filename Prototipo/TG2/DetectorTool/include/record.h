#include "packages.h"
#include "identifier.h"

//===== STATUS
#define _ANOMALOUS_OP -1
#define _NORMAL_OP 1
#define _DROPPED_NODE 0

//===== MODULE
#define _MODULE_RECORD "RECORD"

//===== BORDERS
#define _LOW_LIMIT_STOP -10000

struct COUNT_ADDR
{
	int count;
	struct in_addr sin_addr;
	struct COUNT_ADDR * next;
} *p_dns, *p_ntp, *p_snmp, *p_ssdp;

int packageRegistration(struct in_addr sin_addr, int operation, int protocol);
int updateCountersList(struct in_addr sin_addr, int operation, int protocol);
bool mustKeepHostOnTheList(struct COUNT_ADDR * listAux);
void setProtocolRoot(int protocol, struct COUNT_ADDR * root);
struct COUNT_ADDR * getProtocolRoot(int protocol);
struct COUNT_ADDR * create_node(struct COUNT_ADDR * next, unsigned long addr);
void printAllCounters(int protocol);

