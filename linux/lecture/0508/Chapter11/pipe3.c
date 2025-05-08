#include <stdio.h>
#include <unistd.h>
#define BUF_SIZE 30

int main(int argc, char *argv[])
{
	int fds1[2], fds2[2];
	char str1[]="Who are you?";
	char str2[]="Thank you for your message";
	char buf[BUF_SIZE];
	pid_t pid;
	
	pipe(fds1), pipe(fds2);
	pid=fork();
	
	if(pid==0)
	{
		write(fds1[1], str1, sizeof(str1)); // 1은 쓰기 // 여기서 실행 (2) // fds[1]-> fds[0]
		read(fds2[0], buf, BUF_SIZE); // 여기서 블로킹 (3) // 여기서 읽어오기 (6)
		printf("Child proc output: %s \n",  buf);
	}
	else
	{
		read(fds1[0], buf, BUF_SIZE); // 0은 읽기 // 여기서 블로킹(1) // 여기서 읽어오기 (4)
		printf("Parent proc output: %s \n", buf);
		write(fds2[1], str2, sizeof(str2)); // 여기서 write (5)
		sleep(3);
	}
	return 0;
}