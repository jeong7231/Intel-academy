/***********************************************************/
// [9-1] 변수의 메모리 주소 확인
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a; // 4byte 정수형 메모리
	double b; // 8byte 실수형 메모리 
	char c; // 1byte 문자형 메모리

	printf("int형 변수의 주소 : %p\n", &a);
	printf("double 형 변수의 주소 : %p\n", &b);
	printf("char 형 변수의 주소 : %p\n", &c);
	// &p 주소값 16진수 출력
	return 0;
}
#endif

/***********************************************************/
// [9-2] 포인터 선언과 사용
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a; // 변수선언
	int *pa; // 포인터의 선언

	pa = &a; // a의 주소값을 포인터 pa에 담겠다.

	printf("pa에 들어 있는 값 : %d\n", pa);
	a = 10;
	printf("a에 들어 있는 값 : %d\n", a);

	*pa = 20; // * : 간접 참조 연산자 변수에 할당하는것 처럼 쓸 수 있음
	printf("a에 들어있는 값 : %d\n", a);

	return 0;
}
#endif

/***********************************************************/
// [9-3] 포인터를 사용한 두 정수의 합과 평균 계산
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a = 10, b = 15, total; // a와 b의 총합
	int *pa, *pb; // 각각 a와 b를 가리키는 포인터
	int *pt; // total을 가리키는 포인터
	double avg = 0; // a와 b의 평균
	double *pg; // avg를 가리키는 포인터

	// 1. pa, pb, pt, pg를 각각 초기화!!
	pa = &a;
	pb = &b;
	pt = &total;
	pg = &avg;
	// 2. 간접 참조 연산자 *를 활용하여 total에 a + b를 대입
	*pt = a + b;
	// 3. 간접 참조 연산자 *를 활용하여 avg에 a와 b의 평균을 대입
	*pg = (double)total / 2; // *pt / 2; 도 가능
	

	printf("두 정수의 값 : %d, %d\n", a, b);
	printf("두 정수의 총합 : %d\n", total);
	printf("두 정수의 평균 : %.1lf\n", avg);
}
#endif

/***********************************************************/
// [9-4] 포인터에 const 사용
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	const int num = 10; //const 붙은 변수는 선언과 동시에 초기화 필요
	int a = 10, b = 20;
	const int *pa = &a;
	printf("a의 값 : %d\n", *pa);
	
	pa = &b; // pa가 b의 주소를 가르킨다.
	printf("b의 값 ; %d\n", *pa);

	pa = &a;
	a = 7;
	printf("a의 값 ; %d\n", *pa);

	// const로 포인터 설정 시 간접 참조 불가능
	//*pa = 77; 
	//printf("a의 값 ; %d\n", *pa); 

	return 0;
}
#endif

/***********************************************************/
// [9-5] 주소와 포인터의 크기
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	// sizeof연산자 : sizeof(피연산자) : 피연산자의 데이터 크기 byte로 반환
	int a;
	double b;
	char c;

	// 포인터는 반드시 변수와 데이터 자료형 일치해야함
	int* pa = &a;
	double* pb = &b;
	char* pc = &c;

	// 주소의 크기
	printf("a주소 : %d, b주소 :  %d, c주소:  %d\n", sizeof(&a), sizeof(&b), sizeof(&c));
	// 포인터의 크기
	printf("a포인터 : %d, b포인터 :  %d, c포인터:  %d\n", sizeof(pa), sizeof(pb), sizeof(pc));
	// 포인터가 가르키는 변수의 크기
	printf("a값 : %d, b값 :  %d, c값:  %d\n", sizeof(*pa), sizeof(*pb), sizeof(*pc));

	return 0;
}
#endif

/***********************************************************/
// [9-6] 허용되지 않는 포인터의 대입
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a = 10;
	int* pa = &a;
	double* pd;

	// pa는 a를 가리키는 int형 포인터
	// pd는 double형을 가리킬 수 있는 포인터

	pd = pa; // a의 주소를 가리킬 수 있게 pd에 대입
	// 주의! 형 변환처럼 사용 시 주소 범위 확인 필요

	printf("%lf\n", *pd);

	int* pb;
	pb = pa;
	printf("%d\n", *pa);
	printf("%d\n", *pb);

	return 0;
}
#endif

/***********************************************************/
// [9-7] 포인터를 사용한 두 변수의 값 교환
/***********************************************************/

#if 0
#include <stdio.h>

void swap(int* pa, int* pb);

int main(void)
{
	int a = 10, b = 20;
	// 두 값을 치환(swap) 후 출력
	//printf("%d, %d\n", a, b); // 20, 10

	//int temp;
	//temp = a;
	//a = b;
	//b = temp;

	printf("a : %d, b: %d\n", a, b);
	
	swap(&a, &b); //a와 b의 주소를 넘겨야함

	printf("a : %d, b: %d\n", a, b);

	return 0;
}

// 두 값을 치환하는 함수
void swap(int* pa, int* pb)
{
	// pa -> a의 주소값, 즉, a를 가리킨다.
	// pb -> b의 주소값, 즉, b를 가리킨다.

	int temp;
	temp = *pa; // 변수 a,b 를 쓰지 못하지만 주소를 통해 찾아갈 수 있음
	*pa = *pb;
	*pb = temp;
}
#endif

/***********************************************************/
// [9-8, 9] 다른 함수의 변수 사용하기 8
/***********************************************************/

#if 0
#include <stdio.h>

void swap(int a, int b);

int main(void)
{
	int a = 10, b = 20;
	printf("a : %d, b: %d\n", a, b);

	swap(a, b); // 직접 값으로 스왑하면 안되나?
	printf("a : %d, b: %d\n", a, b); // ㅇㅇ 안됨
	// 직접 메모리를 참조한 값 교환이 아니기 때문에 주소 포인터를 이용하여 교환 해야함
	return 0;
}
void swap(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

#endif

/***********************************************************/
// [9-8, 9] 다른 함수의 변수 사용하기 9?????
/***********************************************************/

#if 0
#include <stdio.h>

void swap(int a, int b);

int main(void)
{
	int a = 10, b = 20;
	printf("a : %d, b: %d\n", a, b);

	swap(a, b); // 직접 값으로 스왑하면 안되나?
	printf("a : %d, b: %d\n", a, b); // ㅇㅇ 안됨
	// 직접 메모리를 참조한 값 교환이 아니기 때문에 주소 포인터를 이용하여 교환 해야함
	return 0;
}
void swap(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

#endif

/***********************************************************/
// [9-도전] 미니 정렬 프로그램
/***********************************************************/

#if 0
#include <stdio.h>

void swap(int* pa, int* pb);
void descending(int* max, int* mid, int* min);

int main(void)
{
	// 세 개의 정수 입력
	int max, mid, min;
	scanf("%d %d %d", &max, &mid, &min); // 10 20 30 엔터

	// 값 3개 넘길 시
	// 가장 큰 값을 max
	// 중간 값을 mid
	// 가장 작은 값을 min으로 바꾸는 함수
	descending(&max, &mid, &min);

	printf("%d %d %d\n", max, mid, min); // 30 20 10 출력

	return 0;
}
// 두 값을 치환하는 함수 swap()
void swap(int* pa, int* pb)
{
	int temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}
void descending(int* max, int* mid, int* min)
{
	// max, mid, min
	// 가장 작은 값을 오른쪽으로 보내거나
	// 1. max, min비교 후 max가 더 작으면 치환
	// 2. mid, min비교 후 mid가 더 작으면 치환
	// 3. max, mid 비교 후 max가 더 작으면 치환
	
	// 가장 큰 값을 왼쪽으로 보내거나
	// 생략

	if (*max < *mid)
	{
		swap(max, mid);
	}
	if (*mid < *min)
	{
		swap(mid, min);
	}
	if (*max < *mid)
	{
		swap(max, mid);
	}
	
	//// max, mid, min
 //   // 가장 작은 값을 오른쪽으로 보내거나
 //   // 1. max, mid비교 후 max가 더 작으면 치환
	//if (*max < *mid) swap(max, mid);
	//// 2. mid, min비교 후 mid가 더 작으면 치환
	//if (*mid < *min) swap(mid, min);
	//// 3. max, mid비교 후 max가 더 작으면 치환
	//if (*max < *mid) swap(max, mid);
}

#endif