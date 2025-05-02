#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
void error_handling(char *message);
int main(int argc, char* argv[])
{
	int sock;
	struct sockaddr_in serv_addr;
	char message[30];
	int str_len;
	if(argc!=3){
		printf("Usage : %s <IP> <port>\n", argv[0]);
		exit(1);
	}
	sock=socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(sock < 0)
		error_handling("socket() error");
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_addr.sin_port=htons(atoi(argv[2]));
	if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) 
		error_handling("connect() error!");
	do {
		printf("문자열을 입력하세요(quit:종료) : ");
		fgets(  );
		if( 입력되 문자열이 "quit" 이면)
			break;
		write() ;    //키보드 입력 문자열을 서버로 전송
		str_len=read(sock, message, sizeof(message)-1);
		message[str_len] = '\0';
		if(str_len < 0)
			error_handling("read() error!");
		printf("Message from server: %s \n", message);  
	} while(1);
	close(sock);
	return 0;
}
void error_handling(char *message)
{
	perror("error_handling()");
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
