#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/signal.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUF_SIZE 30
void error_handling(char *message);
void read_routine(int sock, char *buf);
void write_routine(int sock, char *buf);
void read_childproc(int sig);

pid_t child1_pid;
pid_t child2_pid;
int child1_status = -1;
int child2_status = -1;

int main(int argc, char *argv[])
{
	int sock;
//	pid_t pid;
	char buf[BUF_SIZE];
	struct sockaddr_in serv_adr;
	if(argc!=3) {
		printf("Usage : %s <IP> <port>\n", argv[0]);
		exit(1);
	}
	signal(SIGCHLD,	read_childproc);
	sock=socket(PF_INET, SOCK_STREAM, 0);  
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family=AF_INET;
	serv_adr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_adr.sin_port=htons(atoi(argv[2]));
	
	if(connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
		error_handling("connect() error!");

	child1_pid=fork();
	if(child1_pid==0)
	{
		write_routine(sock, buf);
	}
	else 
	{
		child2_pid=fork();
		if(child2_pid == 0)
		{
			read_routine(sock, buf);  //부모프로세스 실행중 --> 자식프로세스로 실행 
		}
	}
/*	while( 자식 프로세스 둘다 종료시 while문 종료    )
	{
	}	
*/
	do {
		if(child1_status != -1 && child2_status != -1)
		{
			printf("status : %d %d\n",child1_status,child2_status);
			break;
		}
	} while(1);
	close(sock);
	return 0;
}

void read_routine(int sock, char *buf)
{
	while(1)
	{
		int str_len=read(sock, buf, BUF_SIZE);
		if(str_len==0)
			exit(1);  //read_routine

		buf[str_len]=0;
		printf("Message from server: %s", buf);
	}
}
void write_routine(int sock, char *buf)
{
	while(1)
	{
		fgets(buf, BUF_SIZE, stdin);
		if(!strcmp(buf,"q\n") || !strcmp(buf,"Q\n"))
		{	
			shutdown(sock, SHUT_WR);
			exit(2);	//write_routine    
//			return;
		}
		write(sock, buf, strlen(buf));
	}
}
void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
void read_childproc(int sig)
{
    pid_t pid;
    int status;
    pid=waitpid(-1, &status, WNOHANG);
	status = WEXITSTATUS(status);
	if(pid == child1_pid)
		child1_status = status;

	else if(pid == child2_pid)
		child2_status = status;

    printf("removed proc id: %d, return : %d \n", pid,status);

    //지식프로세스의 리턴값 출력
}
