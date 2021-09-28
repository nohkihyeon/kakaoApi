char* getAddress(char* argv){
	int status;
	struct addrinfo hints;
	struct addrinfo *servinfo, *tmp;                // 결과를 저장할 변수
	char host[256];

	memset(&hints, 0, sizeof(hints));               // hints 구조체의 모든 값을 0으로 초기화
	hints.ai_family = AF_UNSPEC;                    // IPv4 IPv6 상관없이 결과 모두 반환
	hints.ai_socktype = SOCK_STREAM;                // TCP stream sockets

	status = getaddrinfo(argv, "80", &hints, &servinfo);
	printf("%d\n", status);

	tmp = servinfo;
	getnameinfo(tmp->ai_addr, tmp->ai_addrlen, host, sizeof(host), NULL, 0, NI_NUMERICHOST);
	
	freeaddrinfo(servinfo);
	return host;
}

int socketConnect(char* host){
	int c_socket;
	struct sockaddr_in c_addr;

	c_socket = socket(PF_INET, SOCK_STREAM, 0);
	memset(&c_addr, 0, sizeof(c_addr));
	c_addr.sin_addr.s_addr = inet_addr(host);
	c_addr.sin_family = AF_INET;
	c_addr.sin_port = htons(80);


	if(connect(c_socket, (struct sockaddr *) &c_addr, sizeof(c_addr)) == -1){
		error_handling("Can not connect");
		close(c_socket);
		return -1;
	}
	return 0;
}
