#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>

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

    do {
        fd_set reads;
        FD_ZERO(&reads);
        FD_SET(sock, &reads);
        FD_SET(stdin_fd, &reads);
        int max_fd = sock + 1;

        // struct timeval timeout;
        // timeout.tv_sec = 30;
        // timeout.tv_usec = 0;

        // int result = select(max_fd, &reads, 0, 0, &timeout);
        int result = select(max_fd, &reads, NULL, NULL, NULL);

        if (result > 0)
        {
            //  ---------------------- select fd:stdin_sd------------------------
            if (FD_ISSET(stdin_fd, &reads))
            {
                //fputs("enter message : ", stdout);
                fgets(message, sizeof(message), stdin);

                if(message == NULL)
                    break;

                str_len = strlen(message)-1;
                message[str_len] = '\0';    //'\n'제거

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
                    fputs("Message from server: ", stdout);
                    fputs(message, stdout);
                    fputc('\n', stdout);
                    fputs("문자열을 입력하세요(quit:종료) : ", stdout);


                    fflush(stdout);
                }

                else if (str_len == 0)
                {
                    fputc('\n', stderr);
                    break;
                }
                else
                    error_handling("read() error!");
            }
            //  -----------------------------------------------------------------
        }

        // else if (result == 0)
        // {
        //     fputc('\n', stderr);
        //     fputs("Time out!!!", stderr);
        //     fputc('\n', stderr);

        //     fputs("문자열을 입력하세요(quit:종료) : ", stderr);
        // }

        else
            error_handling("select() error");

    }while(1);

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
