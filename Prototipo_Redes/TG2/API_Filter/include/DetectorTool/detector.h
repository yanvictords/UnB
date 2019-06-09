#include "../../include/essential.h"

#include <stdbool.h>

#define _DEBUGGER_MODE

//===== STATUS
#define _OK 1
#define _REF_ATTACK_ALERT -1
#define _REJECT_ADDR 0

//===== BORDERS
#define _HIGH_LIMIT 500

//===== MODULE
#define _MODULE_ANALYZER "DETECTOR"

int detector (struct sockaddr_in, char *, bool);
int packageAnalyzer (struct sockaddr_in, char *, bool);
int analyzePackageCounter (long long, struct sockaddr_in, int);
bool getAddrInBlackList (struct sockaddr_in);
void putAddrInBlackList (struct sockaddr_in);
