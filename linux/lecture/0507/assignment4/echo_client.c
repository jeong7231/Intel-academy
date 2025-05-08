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


void read_childproc(int sig)
{
    int status;
    pid_t pid = waitpid(-1, &status, WNOHANG);
    printf("removed proc id : %d return : %d\n", pid, WEXITSTATUS(status));
}

int main(int argc, char *argv[])
{
    int sock;
    char buf[BUF_SIZE];
    struct sockaddr_in serv_adr;
    pid_t pid1, pid2;
    int child_exit_status1 = -1;
    int child_exit_status2 = -1;

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

    signal(SIGCHLD, read_childproc); // 자식 종료 핸들러 등록

    pid1 = fork();
    if(pid1 == 0)
        write_routine(sock, buf);
    else
    {
        pid2 = fork();
        if(pid2 == 0)
            read_routine(sock, buf);
    }

    // 자식 프로세스가 모두 종료될 때까지 대기
    while (child_exit_status1 == -1 || child_exit_status2 == -1)
    {
        if (pid1 > 0 && child_exit_status1 == -1)
        {
            if (waitpid(pid1, &child_exit_status1, WNOHANG) > 0)
            {
                printf("write_routine child process 종료\n");
            }
        }
        if (pid2 > 0 && child_exit_status2 == -1)
        {
            if (waitpid(pid2, &child_exit_status2, WNOHANG) > 0)
            {
                printf("read_routine child process 종료\n");
            }
        }
        sleep(1); // CPU 점유율을 낮추기 위해 잠시 대기
    }

    close(sock);
    printf("메인 프로세스 종료\n");
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
