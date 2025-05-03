#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#define BUFFSIZE 100

void *key_func(void *arg);
void *sock_func(void *arg);
void error_handling(char *message);

static int sock;

int main(int argc, char **argv)
{
    struct sockaddr_in serv_addr;
    // int stdin_fd=fileno(stdin);
    // printf("stdin_fd : %d\n",stdin_fd);

    if(argc!=3)
    {
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

    pthread_t keyboard_thread;
    pthread_t socket_thread;

    //  -------------------- keyboard_thread() -------------------------
    int result_key = pthread_create(&keyboard_thread, NULL, key_func, NULL);

    //  --------------------- socket_thread() --------------------------
    int result_sock = pthread_create(&socket_thread, NULL, sock_func, NULL);

    if(result_key != 0 || result_sock != 0)
    {
        fputs("thread create error", stderr);
        fputc('\n', stderr);
        exit(1);
    }

    // if(result_sock != 0)
    // {
    //     fputs("thread create error", stderr);
    //     fputc('\n', stderr);
    //     exit(1);
    // }

    pthread_join(keyboard_thread, NULL);
    pthread_join(socket_thread, NULL);

    close(sock);

    return 0;
}
//  -------------------- keyboard_thread() -------------------------
void *key_func(void *arg)
{
    char message[BUFFSIZE];
    int str_len;

    fputs("문자열을 입력하세요(quit:종료) : ", stdout);
    fflush(stdout);

    do{
        fgets(message, sizeof(message), stdin);

        if(message == NULL)
            exit(1);

        str_len = strlen(message)-1;
        message[str_len] = '\0';    //'\n'제거

        if(!strcmp(message, "quit"))
            exit(1);

        str_len=write(sock,message,str_len);    //입력 문자열을 서버로 전송
        
        if(str_len <= 0)
            error_handling("write() error");
    }while(1);

    close(sock);
}
//  --------------------------------------------------------------
//  --------------------- socket_thread() ------------------------
void *sock_func(void *arg)
{
    char message[BUFFSIZE];
    int str_len;

    do{
        str_len=read(sock, message, sizeof(message)-1);
        if(str_len > 0)
        {
            message[str_len] = '\0';
            fputs("Message from server: ", stdout);
            fputs(message, stdout);
            fputc('\n', stdout);
            fputs("문자열을 입력하세요(quit:종료) : ", stdout);
            fflush(stdout);
}
        else if(str_len == 0) //서버 소켓 종료시
        {   
            fputc('\n', stderr);
            exit(1);
        }
        else
            error_handling("read() error!");
    }while(1);
}
//  --------------------------------------------------------------
void error_handling(char *message)
{
//	perror("error_handling()");
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

