#include <stdio.h>
int input();
int output(int num);
int main()
{
	int n = input();
	if(!(output(n)))
		printf("Good bye\n");
	return 0;
}
