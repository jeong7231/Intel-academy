#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 100
void error_handling(char *message);
void read_childproc(int sig);

int main(int argc, char *argv[])
{
	int serv_sock, clnt_sock;
	struct sockaddr_in serv_adr, clnt_adr;
	int fds[2]; // 파이프 하나만 만들어둠
	// 서버의 자식프로세스 보내고, 파일 저장 프로세스가 받아서~
	// 단방향 예제라 하나만 만듦
	pid_t pid;
	struct sigaction act;
	socklen_t adr_sz;
	int str_len, state;
	char buf[BUF_SIZE];
	if(argc!=2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	act.sa_handler=read_childproc;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;
	state=sigaction(SIGCHLD, &act, 0);

	serv_sock=socket(PF_INET, SOCK_STREAM, 0);
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family=AF_INET;
	serv_adr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_adr.sin_port=htons(atoi(argv[1]));
	
	if(bind(serv_sock, (struct sockaddr*) &serv_adr, sizeof(serv_adr))==-1)
		error_handling("bind() error");
	if(listen(serv_sock, 5)==-1)
		error_handling("listen() error");
	
	pipe(fds); // 파이프 만들기
	pid=fork(); // 만들어두고 fork해야됨
	if(pid==0)
	{
		FILE * fp=fopen("echomsg.txt", "wt"); // 저수준이 아니라 표준입출력함수 fopen사용
		char msgbuf[BUF_SIZE]; // 메시지 버퍼 잡고
		int i, len;

		for(i=0; i<10; i++) // 열번돌리기
		{
			len=read(fds[0], msgbuf, BUF_SIZE); // 읽기늕 0번 // 첫번째 프로세스는 여기서 블로킹되어있음
			fwrite((void*)msgbuf, 1, len, fp);
		}
		fclose(fp); // 다돌면 파일닫기
		return 0; // 종료
	}

	while(1)
	{
		adr_sz=sizeof(clnt_adr);
		clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_adr, &adr_sz); // 부모프로세스는 여기서 잠들어있음
		if(clnt_sock==-1)
			continue;
		else
			puts("new client connected...");

		pid=fork(); // 여기서 또 부모프로세스가 자식 프로세스 만듦
		if(pid==0)
		{
			close(serv_sock); // 서버 sock 필요없음 이제, 클라이언트에서 잘못된 접근 방지하기 위해
			while((str_len=read(clnt_sock, buf, BUF_SIZE))!=0) // 두번째 자식 프로세스 여기 read에서 블로킹
			{
				write(clnt_sock, buf, str_len); // to echo_sock
				write(fds[1], buf, str_len); // 1번 write fds에 쓰기
			}
			
			close(clnt_sock);
			puts("client disconnected...");
			return 0;
		}
		else
			close(clnt_sock);
	}
	close(serv_sock); // 부모프로세스에선 accept된 fd 필요없음 -> 닫아버림
	return 0;
}

void read_childproc(int sig)
{
	pid_t pid;
	int status;
	pid=waitpid(-1, &status, WNOHANG);
	printf("removed proc id: %d \n", pid);
}
void error_handling(char *message)
{
	fputs(message, stderr); // buf -> message
	fputc('\n', stderr);
	exit(1);
}