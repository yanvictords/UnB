#include "../essential.h"

//===== STATUS
#define _OK 1
#define _REF_ATTACK_ALERT -1
#define _REJECT_ADDR 0

//===== MODULE
#define _MODULE_ANALYZER "DETECTOR"

int detector (struct sockaddr_in addr, char * buffer, bool localNetHost);
int packageAnalyzer (struct sockaddr_in addr, char * buffer, bool localNetHost);
int analyzePackageCounter (long long counter, struct sockaddr_in addr, int protocol);
bool getAddrInBlackList (struct sockaddr_in addr);
void putAddrInBlackList (struct sockaddr_in addr);
