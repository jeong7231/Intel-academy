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
	char message[100]; // 100byte
	int str_len;
	if(argc!=4) // ./client_file <IP> <PORT> <file>
    {
		printf("Usage : %s <IP> <port> <file>\n", argv[0]); // 사용법출력
		exit(1);
	}
	sock=socket(PF_INET, SOCK_STREAM, 0);
    
	if(sock < 0)
		error_handling("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_addr.sin_port=htons(atoi(argv[2]));

	if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) 
		error_handling("connect() error!");

	str_len=read(sock, message, sizeof(message)-1);
    
	if(str_len < 0)
		error_handling("read() error!");


    do {
        
        write(sock, message, strlen(message));
        str_len = read(sock, message, sizeof(message) - 1);

        n = read(sock, buf, sizeof(buf));
        printf("n : %d\n",n);

        if(n > 0)
            write(out,buf, n);

        else if(n == 0)
        {
            fputs("Done ...\n",stderr);
            break;
        }

        else
        {
            perror("read()");
            break;
        }

    } while(1);    





    }while(1)

	close(sock);

	return 0;
}
void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
