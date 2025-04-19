/***********************************************************/
// [13-1] 두 함수에서 같은 이름의 지역 변수를 사용
/***********************************************************/

#if 0
#include <stdio.h>

void assign(void);

int main(void)
{
	// auto 지역 변수 선언 시 사용되는 예약어
	// 생략 시 컴파일러가 자동으로 추가한다.
	auto int a = 10;
	printf("a의 값 : %d\n", a);

	assign();
	printf("a의 값 : %d\n", a);

	return 0;
}

void assign(void)
{
	auto int a = 20;
	printf("assign 함수 내 a의 값 : %d\n", a);
}
#endif

/***********************************************************/
// [13-2] 블록 안에서 사용하는 지역 변수
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a = 10;
	printf("here1 a의 값 : %d\n", a); // 10
	{
		int a = 20;
		printf("here2 a의 값 : %d\n", a); // 20
		{

			int a = 30;
			printf("here3 a의 값 : %d\n", a); // 30
		}
	}

	return 0;
}
#endif

/***********************************************************/
// [13-3] 전역변수
/***********************************************************/

#if 0
#include <stdio.h>

void assign10(void);
void assign20(void);

int a;
int main(void)
{
	// 지역 변수 -> 초기화가 안되어 있으면 사용x
	/*int b;
	printf("%d", b);*/

	// 전역 변수는 컴파일러가 자동으로 초기화
	// int-> 0, double-> 0.0, char -> 0
	printf("함수 호출 전 전역 변수 a의 값 : %d\n", a);

	assign10();
	assign20();

	printf("함수 호출 후 전역 변수 a의 값 : %d\n", a);
	return 0;
}

void assign10(void)
{
	a = 10;
}
void assign20(void)
{
	auto int a;
	a = 20;
}
#endif

/***********************************************************/
// [13-4] 정적 지역 변수
/***********************************************************/

#if 0
#include <stdio.h>

void print_star(void);

int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		print_star();
	}
	
	return 0;
}
void print_star(void)
{
	// static : 정적 지역 변수
	// 함수 블록 사라지더라도 -> 메모리에 저장 공간이 남아 있다.
	// 정적 지역 변수를 계속 사용할 수 있다. (선언된 함수에서)
	// static 키워드가 붙은 놈들은 전용 메모리공간에 저장됨
	// static 키워드 발견 시 static영역에서 호출함

	static int a = 1;
	for (int i = 0; i < a; i++)
	{
		printf("*");
	}
	printf("\n");
	a++;
}
#endif

/***********************************************************/
// [13-5] 레지스터 변수
/***********************************************************/

#if 0
#include <stdio.h>
#include <time.h> //clock() main 실행 시간 측정

int main(void)
{
	// 약수의 합
	// 100 -> 100의 약수의 합 sum 저장

	register int num = 2000000000;
	register long long sum = 0;

	long start = clock();

	for (int i = 1; i <= num; i++)
	{
		sum += i;
	}
	printf("%d의 약수의 합 : %lld\n", num, sum);
	long end = clock();
	// runtime : for문 실행 시간(s)
	double runtime = (double)(end - start) / CLOCKS_PER_SEC;

	printf("runtime : %.3lfs\n", runtime);

	return 0;
}
#endif

/***********************************************************/
// [13-6] 값을 복사해서 전달
/***********************************************************/

#if 0
#include <stdio.h>

int add_ten(int a);

int main(void)
{
	int a = 10;
	printf("함수 호출 전 a : %d\n", a);

	a = add_ten(a);
	printf("함수 호출 후 a : %d\n", a);

	return 0;
}
int add_ten(int a)
{
	a = a + 10;

	return a;
}
#endif

/***********************************************************/
// [13-7] 주소를 전달
/***********************************************************/

#if 0
#include <stdio.h>

void add_ten(int* pa);

int main(void)
{
	int a = 10;

	printf("함수 호출 전 a : %d\n", a);
	add_ten(&a);
	printf("함수 호출 후 a : %d\n", a);

	return 0;
}

void add_ten(int* pa)
{
	*pa = *pa + 10;
}
#endif

/***********************************************************/
// [13-8] 주소를 반환하는 함수
/***********************************************************/

#if 0
#include <stdio.h>

int* sum(int a, int b);

int main(void)
{
	int a = 10, b = 20;
	// 두 정수의 합 sum();
	// sum (10 , 20);
	sum(a, b);

	//int result = sum(a, b);
	int* resp = sum(a, b);
	printf("두 정수의 합 : %d\n", *resp);

	return 0;
}

int* sum(int a, int b)
{
	// 주소값을 반환 시
    // static 키워드를 사용하자
	static int result;
	result = a + b;

	return &result;
}
#endif

/***********************************************************/
// [13-도전] 전역 변수 교환 프로그램
/***********************************************************/

#if 0
#include <stdio.h>

void swap(void);

int a, b; //전역 변수 a와 b선언

int main(void)
{
	//전역 변수 초기화
	a = 10;
	b = 20;
	printf("교환 전 a : %d, b : %d\n", a, b);

	swap(); // 전역 변수 a와 b 치환
	printf("교환 후 a : %d, b : %d\n", a, b);

	return 0;
}
void swap(void)
{
	// 전역 변수 a 와 b 치환
	// 전역 변수 : 모든 함수에서 바라볼 수 있다.
	int temp;
	temp = a;
	a = b;
	b = temp;
}
#endif

