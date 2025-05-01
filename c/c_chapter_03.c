/***********************************************************/
// [3-1] 변수의 선언과 사용
/***********************************************************/

#if 0 
#include <stdio.h>

int main(void)
{
	int a; 
	//변수의 선언 : 메모리에 변수 공간을 만드는 작업
	// int 형 변수 -> 4byte 크기로 메모리 준비
	a = 10; 
	//변수에 값을 할당 
	//최초 할당 => 초기화

	//1. 정수형 변수 b와 c를 선언(int로)
	//2. 실수형 변수 da 선언 (double로)
	//3. 문자형 변수 ch 선언 (char로)
	//4. a에 들어있는 값으로 b를 초기화
	//5. a에 들어있는 값에 20을 더해 c를 초기화
	//6. da를 3.5로 초기화
	//7. ch를 문자 'A'로 초기화
	//8. 모든 변수 출력

	//printf("%d", a);
	//return 0;

	int b, c;
	double da;
	char ch;
	b = a;
	c = a + 20;
	da = 3.5;
	ch = 'A';

	printf("변수 a의 값 : %d\n", a);
	printf("변수 b의 값 : %d\n", b);
	printf("변수 c의 값 : %d\n", c);
	printf("변수 da의 값 : %.1lf\n", da);
	printf("변수 ch의 값 : %c\n", ch);


}
#endif

/***********************************************************/
// [3-2] char형 변수의 사용
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	char ch1 = 'A';
	char ch2 = 65;

	printf("문자 %c의 아스키 코드 값 : %d\n", ch1, ch1);
	printf("아스키 코드 값이 %d인 문자 : %c\n", ch2, ch2);

	return 0;
	//내일 할 for문 A~Z 출력해라 할때 
}
#endif

/***********************************************************/
// [3-3] 여러가지 정수형 변수
/***********************************************************/

#if 0 
#include <stdio.h>

int main(void)
{
	//short, int, long, longlong
	//2^32-1
	//<- 0 ->
	//2^31 ~ 0 ~ 2^31-1

	// overflow : 가장 큰 값에서 표현할 수 있는 범위를 넘으면 가장 작은 값이 됨!
    // underflow : 가장 작은 값에서 표현할 수 있는 범위를 넘으면 가장 큰 값이 됨!
    // short 2byte = 16bit = 2^16 = 65536 -> -32768 ~ 0 ~ 32767

	short sh = 32767; //short 최댓값
	int in = 2147483647; //int 최댓값
	long ln = 2147483647; //long 최댓값
	long long lln = 1234512345645; //아주 큰 값 초기화

	// %d : int형
	// %ld : long형
	// %lld : long long형

	//특별한 경우가 아니라면 정수는 int, 실수는 double 쓰는게 좋음
	printf("short형 변수 출력 : %d\n", sh);
	printf("int형 변수 출력 : %d\n", in);
	printf("long형 변수 출력 : %ld\n", ln);
	printf("long long형 변수 출력 : %lld\n", lln);

	return 0;
}
#endif

/***********************************************************/
// [3-4] unsigned를 잘못 사용한 경우
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	unsigned int a;
	
	a = 4294967295; // int 최댓값 
	printf("%u\n", a); //unsinged는 %u 사용, %d는 오버플로우 발생함
	a = -1;
	printf("%u\n", a);
	return 0;
}
#endif

/***********************************************************/
// [3-5] 유효 숫자 확인
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	float ft = 1.2345678901234567890; 
	//선언과 동시에 초기화 가능
	double db = 1.2345678901234567890;
	long double ldb = 1.2345678901234567890;

	printf("%.20f\n", ft);
	printf("%.20lf\n", db);
	printf("%.20llf\n", ldb);
	// 오차 발생함 -> ieee 754 표준에 따라 근사값으로 들어가기 때문
	// 더큰 범위에 넣었다고 더 근사하는것은 아님
	// 결론 -> 실수는 아묻따 double 쓰자
	return 0;
}
#endif

/***********************************************************/
// [3-6] char 배열에 문자열 저장
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	char fruit[7] = "orange"; //6자 할당
	//문자열 배열 줄여서 문자열
	// 배열 : [] 사용
	// 반드시 크기가 할당
	// 정적으로 할당
	// char 변수명[크기] -> 문자열 (string)
	// 문자열은 c언어에서 구분하기 위해
	// 끝에 널 문자 ('\0') 이 들어간다
	// !주의사항! 문자열 길이 +1 이상으로 배열의 길이 결정

	// 기본 자료형 
	// 정수형 : short, int, long, long long
	// 실수형 : float, double, long double
	// 문자형 : char
	// 절차지향에서는 기본 자료형에서만 배열 사용 가능
	printf("%s\n", fruit);

	return 0;
}
#endif

/***********************************************************/
// [3-7] char 배열에 문자열 복사
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h> //문자열 관련 기능 포함 헤더

// strcpy()

int main(void)
{
	char fruit[20] = "banana";
	// fruit 문자열에 해당 문자를 덮어쓰기
	strcpy(fruit, "apple");

	printf("%s\n", fruit);

	return 0;
}
#endif

/***********************************************************/
// [3-8] const를 사용한 변수
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int income = 0;
	double tax;
	income = 400;
	const double tax_rate = 0.065;
	tax = income * tax_rate;
	
	//tax_rate = 0.1;

	//코드를 엄격하게 설계 할 때 const 사용
	//뒤에서 재할당 불가, 선언과 동시에 할당해줘야함

	printf("%lf\n", tax);

	return 0;
}
#endif

/***********************************************************/
// [3-확인문제] 2 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a = 0;

	a = a + 1; //1
	a = a + 2; //3
	a = a + 3; //6
	printf("a : %d", a); //6

	return 0;
}
#endif

/***********************************************************/
// [3-연습문제] 3
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int kor, eng, math, sum;

	kor = 70;
	eng = 80;
	math = 90;

	sum = kor + eng + math;

	printf("%d\n", sum);

	return 0;
}
#endif

/***********************************************************/
// [3-9] scanf 함수를 사용한 키보드 입력
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int age;

	printf("나이를 입력하세요 : ");
	scanf("%d", &age);
	
	printf("만나이 : %d\n", age - 2);
	return 0;
}
#endif

/***********************************************************/
// [3-10] scanf 함수를 사용한 연속 입력
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int age;
	double height;

	printf("나이와 키를 입력하세요 : ");
	scanf("%d %lf", &age, &height);
	printf("나이는 %d살, 키는 %.1lfcm입니다.\n", age, height);

	return 0;
}
#endif

/***********************************************************/
// [3-11] 문자와 문자열 입력
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	char grade;
	char name[20];

	printf("학점 입력 : ");
	scanf("%c", &grade);
	printf("이름 입력 : "); //한글은 한글자당 2byte
	scanf("%s", name); // 문자열에는 &사용하지 않는다.
	printf("%s의 학점은 %c 입니다.\n", name, grade);

	return 0;
}
#endif