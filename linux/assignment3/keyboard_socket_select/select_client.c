#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUFFSIZE 100

void error_handling(char *message);

int main(int argc, char* argv[])
{
    int sock;
    struct sockaddr_in serv_addr;
    char message[BUFFSIZE];
    int str_len;
    int stdin_fd = fileno(stdin);

    if (argc != 3) 
    {
        printf("Usage : %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0)
        error_handling("socket() error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
        error_handling("connect() error!");

    fputs("문자열을 입력하세요(quit:종료) : ", stdout);
    fflush(stdout);

    while (1) {
        fd_set reads;
        FD_ZERO(&reads);
        FD_SET(sock, &reads);
        FD_SET(stdin_fd, &reads);
        int max_fd = sock + 1;

        struct timeval timeout;
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;
        
        int result = select(max_fd, &reads, 0, 0, &timeout);

        if (result > 0) 
        {
            //  ---------------------- select fd:stdin_sd------------------------
            if (FD_ISSET(stdin_fd, &reads)) {
                if (fgets(message, sizeof(message), stdin) == NULL)
                    break;

                str_len = strlen(message);
                if (message[str_len - 1] == '\n')
                    message[str_len - 1] = '\0';

                if (!strcmp(message, "quit"))
                    break;

                str_len = write(sock, message, strlen(message));
                if (str_len <= 0)
                    error_handling("write() error");
            }
            //  -----------------------------------------------------------------    

            //  ---------------------- select fd:sock ---------------------------
            if (FD_ISSET(sock, &reads)) 
            {
                str_len = read(sock, message, sizeof(message) - 1);

                if (str_len > 0) 
                {
                    message[str_len] = '\0';
                    printf("Message from server: %s\n", message);
                    printf("문자열을 입력하세요(quit:종료) : ");
                    fflush(stdout);
                } 
                
                else if (str_len == 0)
                    break;
                
                else 
                    error_handling("read() error!");
            }
            //  -----------------------------------------------------------------
        } 
        
        else if (result == 0) 
            fputs("Time out!!!\n", stderr);
        
        else 
            error_handling("select() error");

    }

    close(sock);

    return 0;
}
void error_handling(char *message)
{
//  perror("error_handling()");
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}


