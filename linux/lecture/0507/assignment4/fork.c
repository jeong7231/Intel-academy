#include <stdio.h>
#include <unistd.h>
int gval=10;

int main(int argc, char *argv[])
{
	pid_t pid;
	int lval=20;
	gval++, lval+=5; //gval = 11, lval = 25
	
	pid=fork();	// pid 0보다 작으면 에러 출력하는 예외 처리 하기 
    printf("pid %d \n",pid);

	if(pid==0)	// if Child Process
		gval+=2, lval+=2;
	else			// if Parent Process
		gval-=2, lval-=2;
	
	if(pid==0)
    {
        printf("Child Proc: [%d, %d] \n", gval, lval);
       // sleep(10);
    }
	else
    {
        printf("Parent Proc: [%d, %d] \n", gval, lval);
        sleep(20);
    }
	return 0;
}
