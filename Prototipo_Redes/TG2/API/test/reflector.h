#include "dnsPackage.h"

#define _DNS_PORT 5003

#define _VICTIM_PORT 3000
#define _VICTIM_ADDRESS "192.168.25.6"

#define _LEN 65500

struct sockaddr_in attacker, victim;

void startAttack();
void checkSocket();
void toAttack();
void bindPort();

int sck;
_Bool _running;
