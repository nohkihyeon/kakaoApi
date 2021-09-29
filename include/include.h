/*========================================================================
 * Header Files 
 *========================================================================*/
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <jansson.h>
#include <stdbool.h>


/*========================================================================
 * Function Prototype
 *========================================================================*/
int getAddr(char *argv[]);
char* writeBuffer();
int getAddress(char*);
int dataParsing(char*);
void error_handling(char*);

char buffer[BUFSIZ];
