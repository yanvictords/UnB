#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define _PORT 3000
#define _LEN 65536

struct sockaddr_in server, client;
_Bool _running;
