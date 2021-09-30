/*
 * Author   : Noh, Ki-Hyeon
 * Filename : writeJson.c
 * Release  :
 * Date     :
 *
 * Description :
 *
 * Notes :
 * ===================
 * History
 * ===================
 *
*/

#include <include.h>

char* writeBuffer(){

	static char writenData[BUFSIZ];
	int left_len, sent_len, recv_len, bytes;
	char rcvBuffer[BUFSIZ];
	left_len = strlen(buffer);
	sent_len = 0;
	do{
		bytes = write(c_socket, buffer + sent_len, left_len - sent_len);
		if(bytes  <0)
			error_handling("write()Error\n");
		if(bytes ==0)
			break;
		sent_len +=bytes;
	}while(sent_len < left_len);

	left_len = strlen(rcvBuffer);
	sent_len = 0;
	do{
		memset(rcvBuffer, 0, sizeof(rcvBuffer));
		bytes = read(c_socket, rcvBuffer, 1024);
		fprintf(stdout, "%s ", rcvBuffer);

		if(bytes < 0)
			error_handling("read() error\n");
		if(bytes ==0)
			break;
		recv_len +=bytes;
		strcat(writenData, rcvBuffer);
	}while(1);

	if(recv_len == left_len)
		error_handling("Error\n");

	return writenData;
}
