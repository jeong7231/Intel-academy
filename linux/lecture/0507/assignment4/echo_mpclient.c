#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <signal.h>

#define BUF_SIZE 30
void error_handling(char *message);
void read_routine(int sock, char *buf);
void write_routine(int sock, char *buf);


int child_count = 0; // 전역 변수 추가가

void mychild(int sig)
{
    int status;
    pid_t pid = wait(&status);
    printf("removed proc id : %d return : %d\n", pid, WEXITSTATUS(status));
    child_count++;
}


int main(int argc, char *argv[])
{
    int sock;
    char buf[BUF_SIZE];
    struct sockaddr_in serv_adr;
    pid_t pid1, pid2;

    if(argc!=3) {
        printf("Usage : %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    sock=socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        error_handling("socket() error");

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family=AF_INET;
    serv_adr.sin_addr.s_addr=inet_addr(argv[1]);
    serv_adr.sin_port=htons(atoi(argv[2]));

    if(connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
        error_handling("connect() error!");

    signal(SIGCHLD, mychild);  // 자식 종료 핸들러 등록

    pid1 = fork();
    if(pid1 == 0) 
        write_routine(sock, buf);
    else
        pid2 = fork();
        if(pid2 == 0) 
            read_routine(sock, buf);

    // while 문 안에서 자식 프로세스 두개가 종료될 때 까지 대기
    while(child_count < 2)
        sleep(1);

    close(sock);
    return 0;
}

void read_routine(int sock, char *buf)
{
    while(1)
    {
        int str_len=read(sock, buf, BUF_SIZE); // 서버에서 데이터 수신 될 때 까지만만
        if(str_len==0)
            exit(1);

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
            exit(2);

            // return;
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

