/***********************************************************/
// [7-1] 두 정수의 합을 반환하는 함수
/***********************************************************/

#if 0
#include <stdio.h>

int sum(int num1, int num2); //함수 선언 변수이름 생략해도됨

int main(void)
{
	//함수 정의 : 함수명, 매개변수(parameter), 반환형
	//함수 호출 : 함수명(전달인자1, 전달인자2, ...(argument))
	//함수 선언 : 절차지향 프로그래밍에서 메모리 공간을 미리 할당하기위해 필요
	//            정의 그대로 작성!! 단, 몸통(Body)없이

	printf("%d\n", sum(3,5));
	printf("%d\n", sum(10, 20));

	return 0;
}

//함수 정의 : 두 정수를 더해서 반환하는
//-함수명 : sum
//-매개변수 : num1, num2
//-반환형 : int
// 반환형 함수명(매개변수1, 매개변수2, ...)
int sum(int num1, int num2)
{
	int result = num1 + num2 + 1;

	return result;
}


#endif

/***********************************************************/
// [7-확인] 두 실수의 평균을 반환하는 함수
/***********************************************************/

#if 0
#include <stdio.h>
double average(double a, double b);

int main(void)
{
	printf("%.2lf\n", average(1.5, 3.4));

	return 0;
}

double average(double a, double b)
{
	double result = (a + b) / 2;

	return result;
}
#endif

/***********************************************************/
// [7-2] 매개변수가 없는 함수
/***********************************************************/

#if 0
#include <stdio.h>

int get_num();

int main(void)
{
	int input1 = get_num();
	int input2 = get_num();

	printf("%d\n", input1 + input2);

	return 0;
}

//양수를 입력 받아 반환하는 함수!!
int get_num()
{
	int result;

	printf("양수 입력 : ");
	scanf("%d", &result);

	return result;
}



#endif

/***********************************************************/
// [7-3] 반환값이 없는 함수
/***********************************************************/

#if 0
#include <stdio.h>

void print_char(char ch, int count);

int main(void)
{
	//print_char('*', 3);
	for (int i = 1 ; i <= 5; i++)
	{
		print_char('*', i);
	}

	return 0;
}

// 문자와 개수를 전달하면 가로로 출력하는 함수!!
// 예) *과 3전달 시 *** 출력
// void : 타입 없음 (현재는 반환 타입 없음)
void print_char(char ch, int count)
{
	// ch : *
	// count : 3

	for (int i = 1; i <= count; i++)
	{
		printf("%c", ch);
	}
	printf("\n");
	return; //반환 없음 (생략 가능)
}

#endif

/***********************************************************/
// [7-4] 매개변수와 반환값이 모두 없는 함수
/***********************************************************/

#if 0
#include <stdio.h>

void print_line(void);

int main(void)
{
	print_line();
	printf("이름	학번	전공	MBTI \n");
	print_line();

	return 0;
}

// --- x 30
void print_line(void)
{
	for (int i = 1; i <= 30; i++)
	{
		printf("-");
	}
	printf("\n");
}


#endif

/***********************************************************/
// [7-5] 재귀 함수
/***********************************************************/

#if 0
#include <stdio.h>
int fibonacci(int num);
int main(void)
{	
	// 재귀함수를 통해 피보나치 수열 20번째 항 구하기
	// 재귀함수는 함수 호출 횟수가 커지면 커질수록
	// 연산 속도, 연산량이 기하급수적으로 늘어난다.
	printf("%d\n", fibonacci(20));
	
	return 0;
}
//피보나치 수열을 구하는 함수
int fibonacci(int num)
{
	if (num <= 2)
	{
		return 1;
	}

	return fibonacci(num - 2) + fibonacci(num - 1);
	// fibonacci(3) = fibonacci(1) + fibonacci(2)
	// fibonacci(10 = fibonacci(8) + fibonacci(9)
	// fibonacci(num) = fibonacci(num-2) + fibonacci(num-1)
}


#endif

/***********************************************************/
// [7-6] 연습1
/***********************************************************/

#if 0
#include <stdio.h>
int abs(int num);

int main(void)
{
	printf("%d\n", abs(-20));

	return 0;
}
// 절댓값을 반환하는 abs함수

int abs(int num)
{
	int result = num * -1;

	return result;
}

int abs2(int num) 
{
   // 기능구현
   int result;

   if (num > 0)
   {
      result = num;
   }
   else
   {
      result = -num;
   }

   return result;
}

int abs3(int num)
{
	return num > 0 ? num : -num;
}

#endif

/***********************************************************/
// [7-7] 완전수 구하기
/***********************************************************/

#if 0
#include <stdio.h>

int is_divisor(int num1, int num2);
void print_divisors(int num);
int get_sum_of_divisors(int num);
int is_perfect_number(int num);
int find_perfect_number(void);

int main(void)
{
	printf("%d\n", is_divisor(10, 2));
	printf("%d\n", is_divisor(10, 3));
	
	print_divisors(10);
	print_divisors(12);

	printf("%d\n", get_sum_of_divisors(10));
	printf("%d\n", get_sum_of_divisors(28));

	printf("%d\n", is_perfect_number(10));
	printf("%d\n", is_perfect_number(28));

	// 첫 번째 완전수 : 6
	// 두 번재 완전수 : 28
	// 세 번째 완전수를 찾아주세요 : 2~1000 사이에 있음
	// 네 번째 완전수를 찾아주세요 : 1000 ~ 10000 사이에 있음
	// 다섯 번째 완전수를 찾지는 못합니다 : 10000 ~ 1억 (다른 알고리즘이 있음)

	find_perfect_number();

	return 0;
}
// step1. is_divisor()
int is_divisor(int num1, int num2)
{
	if (num1 % num2 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
// step2. print_divisors()
void print_divisors(int num)
{
	printf("%d의 약수 : ", num);
	for (int i = 1; i <= num; i++)
	{
		if (num % i == 0)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
}
// step3. get_sum_of_divisors()
int get_sum_of_divisors(int num)
{
	//약수의 합을 반환
	int sum = 0;

	/*for (int i = 1; i <= num; i++)
	{
		if (num % i == 0)
		{
			sum += i;
		}
	}
	return sum;*/

	for (int i = 1; i <= num; i++)
	{
		if (is_divisor(num, i)) //약수면 참이되면서 실행
		{
			sum += i;
		}
	}
	return sum;
}
// step4. is_perfect_number()
int is_perfect_number(int num)
{
	// 완전수란?
	// 자기 자신을 제외한 양의 약수의 합이
	// 자기 자신이 되는 수
	// 6 -> 완전수 -> 약수의 총합 12
	// 28 -> 완전수 -> 약수의 총합 56
	// 약수의 총합/2 = 자기 자신
	
	// if (num == (get_sum_of_divisors(num)/2))
	/*
	if (get_sum_of_divisors(num) == num*2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	*/
	return get_sum_of_divisors(num) == num * 2; //참이면 1, 거짓이면 0 이니까 바로 가능
}
// step5. find_perfect_number()
int find_perfect_number(void)
{
	for (int i = 2; i <= 10000; i++)
	{
		if (is_perfect_number(i) == 1)
		{
			printf("%d ", i);
		}
	}
}
#endif

/***********************************************************/
// [6-9] Up-Down 프로그램
/***********************************************************/

#if 0
#include <stdio.h>
#include <stdlib.h> //rand(), srand()
#include <time.h> // time()
int main(void)
{
	srand(time(NULL)); // 시드 초기화 //ms단위로 시간이 들어감
	// 1 ~ 100 사이의 랜덤한 정수 추출
	int random_number = rand() % 100 + 1;
	int find_number;
	while (1)
	{
		printf("정수 입력 : ");
		scanf("%d", &find_number);


		if (random_number == find_number)
		{
			printf("정답!!\n");
			break; //return 써도 되긴함 근데 while 문 이후로 안불러옴
		}
		else if (random_number > find_number)
		{
			printf("입력한 숫자보다 큽니다.\n");
		}
		else if (random_number < find_number)
		{
			printf("입력한 숫자보다 작습니다.\n");
		}

	}
	printf("프로그램 종료");
	return 0;
}

#endif