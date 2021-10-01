/*
 * Author   : Noh, Ki-Hyeon
 * Filename : search_keyword.c
 * Release  :
 * Date     :
 * Description : 
 *
 * Github <https://github.com/nohkihyeon/kakaoApi>
 *
 * Notes :
 * ===================
 * History
 * ===================
 *
 */

#include <include.h>
#include <dataSet.h>

int main(int argc, char *argv[]){
	char* data;

	if(argc !=4){
		fprintf(stderr, "Usage : <host> <resource> <API_KEYS>\nex) ./keywordSearch_exe dapi.kakao.com  /v2/local/search/keyword.json?query=<query> <API_KEYS>\n");
		return -1;
	}

	/* 1. Get Address */
	if(getAddr(argv) < 0) return -1;

	/* 2. Get json data*/
	data = writeBuffer();

	/* 3. Parsing json data*/
	dataParsing(data);

	close(c_socket);
	return 0;
}

void error_handling(char* msg){
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}
