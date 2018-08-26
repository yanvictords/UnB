#include "packages.h"
#include "decoder.h"
#include "record.h"
#include "identifier.h"
#include "feedback.h"

//#define _DEBUGGER_MODE

//===== STATUS
#define _OK 1
#define _REF_ATTACK_ALERT -1
#define _REJECT_ADDR 0

//===== BORDERS
#define _LOW_LIMIT -5
#define _HIGH_LIMIT 500

//===== MODULE
#define _MODULE_ANALYZER "ANALYZER"

//===== FILE
#define _BLACK_LIST_FILE "blacklist.txt"

int package_analyzer(struct sockaddr_in addr, char * buffer, bool localNetHost);
int analyzePackageCounter(int counter, struct sockaddr_in addr, int protocol);
bool getAddrInBlackList(struct sockaddr_in addr);
void putAddrInBlackList(struct sockaddr_in addr);
