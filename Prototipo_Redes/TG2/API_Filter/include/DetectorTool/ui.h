#include "../../include/essential.h"

#define RED "\033[0;31m"
#define BOLD_RED "\033[1;31m"
#define GREEN "\033[0;32m"
#define BOLD_GREEN "\033[1;32m"
#define YELLOW "\033[0;33m"
#define BOLD_YELLOW "\033[01;33m"
#define BLUE "\033[0;34m"
#define BOLD_BLUE "\033[1;34m"
#define MAGENTA "\033[0;35m"
#define BOLD_MAGENTA "\033[1;35m"
#define CYAN "\033[0;36m"
#define BOLD_CYAN "\033[1;36m"
#define END "\033[0m"

#define PRINT_COLOR(color, string) printf("%s%s%s", color, string, END)

void printBegin ();
void printEnd ();
void printQueryType (char * module, int operation);
void printUnknownProtocol (char * module);
void printOkStatus (char * module, int status);
void printErrorStatus (char * module, int status, char * exception);
void printAnotherStatus (char * module, int status, char * event);
void printGetInBlackListStatus (char * module, int status, struct sockaddr_in addr);
void printPutInBlackListStatus (char * module, int status, struct sockaddr_in addr);
void printFileNotFound (char * module, char * file);
void printProtocolName (char * module, int protocol);
void printAlert (char * module, struct sockaddr_in addr, int protocol, int counter);
void printAlertForgedReflector (char * module, struct sockaddr_in addr, int protocol, int counter);
void printTime ();
char * getProtocolName (int protocol);
