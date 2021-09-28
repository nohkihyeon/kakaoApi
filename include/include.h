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
char* getAddress(char*);
int socketConnect(char*);
