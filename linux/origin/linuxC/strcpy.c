#include <stdio.h>
//#include <string.h>
#define PI 3.14159
char* user_strcpy(char*,const char*);
int main(int argc, char* argv[])
//int main(int argc, char** argv)
{
	char fruit[20] = { 0 };
//	fruit = "straw";
	printf("%s%lf\n", fruit,PI);
		
//	strcpy(fruit, "strawberry");
	user_strcpy(fruit, "strawberry");
    printf("%s\n",fruit);
	printf("%s\n",user_strcpy(fruit, "strawberry"));
	return 0;
}

char* user_strcpy(char* dp, const char* sp)
//char* user_strcpy(char dp[], const char sp[])
{
	char* temp = dp;
/*
	while (*sp != '\0')
	{
		*dp = *sp;				//fruit[0] = 's'
		dp++;
		sp++;
	}
	*dp = '\0';
*/
	int i = 0;
	while (sp[i] != '\0')
	{
		dp[i] = sp[i];				//fruit[0] = 's'
		i++;
	}
	dp[i] = '\0';
	return temp;
}
