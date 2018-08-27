#include "packages.h"
#include <time.h>

#define _LEN 65536

void printBegin();
void printEnd();
void printQueryType(char * module, int operation);
void printUnknownProtocol(char * module);
void printOkStatus(char * module, int status);
void printErrorStatus(char * module, int status, char * exception);
void printAnotherStatus(char * module, int status, char * event);
void printGetInBlackListStatus(char * module, int status, struct sockaddr_in addr);
void printPutInBlackListStatus(char * module, int status, struct sockaddr_in addr);
void printFileNotFound(char * module, char * file);
void printProtocolName(char * module, int protocol);
void printAlert(char * module, struct sockaddr_in addr, int protocol, int counter);
char * getProtocolName(int protocol);
void printTime();
