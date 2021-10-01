#ifndef HEADER_H
#define HEADER_H
/*========================================================================
 * Header Files 
 *========================================================================*/
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>				 // for close
#include <arpa/inet.h>	     	 // inet_addr
#include <jansson.h>
#include <dataSet.h>

/*========================================================================
 * Function Prototype
 *========================================================================*/
int getAddr(char *argv[]);
char* writeBuffer();
int getAddress(char*);
int dataParsing(char*);
void error_handling(char*);

char buffer[BUFSIZ];
DataSet dataSet;
int c_socket;

#endif
