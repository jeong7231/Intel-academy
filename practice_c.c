#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#pragma warning(disable:4477)
#pragma warning(disable:6328)
#pragma warning(disable:6031)
//04月09日(水)#2
/***********************************************************/
// [0-0] Hello world 출력해보기
/***********************************************************/

#if 0 //0 비활성 1 활성
#include <stdio.h>
	
int main(void)
{
	// 빌드 ->  솔루션 빌드 (단축키 Ctrl+Shift+B)
	printf("Hello world!");
	return 0;
}
#endif

/***********************************************************/
// [2-3] 제어문자를 사용한 출력
/***********************************************************/

#if 0 
#include <stdio.h>

int main(void)
{
	printf("Goot\bd\tChance\n");
	printf("Cow\rW\a\n");
	return 0;
}
#endif

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

/***********************************************************/
// [백준-1008] A/B
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	double a, b, s;

	scanf("%lf %lf", &a, &b);

	s = a / b;

	printf("%.15lf", s); //오차 1e-10까지 -> 15자리까지 표시해야됨

	return 0;
}
#endif

/***********************************************************/
// [4-1] 대입, 더하기, 빼기, 곱하기, 음수 연산
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a, b;
	int sum, sub, mul, inv;

	a = 10;
	b = 20;
	sum = a + b;
	sub = a - b;
	mul = a * b;
	inv = -a;

	printf("a의 값 :%d, b의 값:%d\n", a, b);
	printf("덧셈 : %d\n", sum);
	printf("뺄셈 : %d\n", sub);
	printf("곱셈 : %d\n", mul);
	printf("a의 음수 연산 : %d\n", inv);


	return 0;
}
#endif

/***********************************************************/
// [4-2] 나누기, 나머지 연산자
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	double apple; //실수
	int banana; //정수
	int orange; //정수

	apple = 5.0 / 2.0; 
	// 1. 우항 먼저 실행 : 5.0 / 0.2
	// 2. 우항 연산 : 실수 / 실수 -> 실수
	// 3. 실수 결과를 apple에 대입
	banana = 5 / 2;
	// 1. 우항 먼저 실행 : 5 / 2
	// 2. 우항 연산 : 정수 / 정수 -> 정수 :2
	// 3. 정수 결과를 banana에 대입
	orange = 5 % 2;
	// 결과는 정수!!

	printf("apple : %.1lf\n", apple);
	printf("banana : %d\n", banana);
	printf("orange : %d\n", orange);

	return 0;
}
#endif

/***********************************************************/
// [4-2-1] 최소 동전 구하기
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	// 자판기에 동전을 투입
	// 잔돈을 출력하는 프로그램
	
	int input = 770;
	int price = 100; 
	int change = input - price;
	// change = 900won
	// ==출력문구==
	// 50원짜리 : 1개
	// 10원짜리 : 2개
	// 500원짜리 : 1개
	// 100원짜리 : 4개  

	printf("잔돈 : %d원\n", change );
	printf("500원짜리 : %d개\n", change / 500 );
	//printf("100원짜리 : %d개\n", (change - 500 * (change / 500)) / 100);
	printf("100원짜리 : %d개\n", change % 500 / 100);
	printf("50원짜리 : %d개\n", change % 100 / 50);
	// change - 500 * 500원개수 - 100 * 100원 개수
	// => 770 % 100 : 70 
	printf("10원짜리 : %d개\n", change % 50 / 10);
	
	return 0;
}
#endif

/***********************************************************/
// [4-2] 실습2
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int time = 7533; // 총 초(sec)의 수가 주어진다.
	// ==출력결과==
	// 2시간 5분 33초
	int m, h, s;
	h = time / (60 * 60);
	m = time % (60 * 60) / 60;
	s = time % 60;
	
	printf("%d시간 %d분 %d초", h, m, s);
	return 0;
}
#endif

/***********************************************************/
// [4-3] 증감 연산자의 연산
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a = 10, b = 10;
	// 증감 연산자 : 증가연산자 + 감소연산자 
	++a;
	--b;

	printf("a : %d\n", a);
	printf("b : %d\n", b);
	return 0;
}
#endif

/***********************************************************/
// [4-4] 전위 표기와 후위 표기를 사용한 증감 연산
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a = 5, b = 5;
	int prefix, postfix;
	prefix = (++a) * 3; //먼저 1증가시키고 증가시킨 상태에서 연산
	postfix = (b++) * 3; //먼저 사용되고 문장이 끝난 뒤에 1증가 (대개 이거 많이 씀)

	printf("%d %d\n", prefix, postfix);
	printf("%d %d\n", a, b);

	return 0;
}
#endif

/***********************************************************/
// [4-5] 관계 연산의 결과값 확인
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a = 10, b = 20;
	printf("%d\n", a > b); // a가 b보다 큼? No! => 0
	printf("%d\n", a < b); // a가 b보다 작음? Yes! => 1
	printf("%d\n", a >= b); // 0
	printf("%d\n", a <= b); // 1
	printf("%d\n", a == b); // 0
	printf("%d\n", a != b); // 1
	// c언어에서 거짓을 정수로 출력하면 -> 0
	// c언어에서 참을 정수로 출력하면 -> 1
	
	// 0을 넣으면 "거짓"의 역할
	// 1을 넣으면 "참"의 역할
	// C는 논리타입이 없다~
	// -1을 넣어도 3을 넣어도 "참"의 역할을한다 -> 0 이외 모두 "참"
	// -> while 문에 변수대신 숫자쓰기도함
	return 0;
}
#endif

/***********************************************************/
// [4-6] 논리 연산의 결과값 확인
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	// && (AND) : 논리곱
	// 오늘의 날씨는 흐리다 : 참
	// 오늘은 수요일이다 : 참
	// Input output
	//  1 1    1
	//  1 0    0
	//  0 1    0
	//  0 0    0
	// || (OR)  : 논리합
	// Input output
	//  1 1    1
	//  1 0    1
	//  0 1    1
	//  0 0    0
	// !  (NOT) : 논리 부정
	// Input output
	//   1      0
	//   0      1

	int a = 30;

	printf("(a > 30) && (a < 20) : %d\n", (a > 30) && (a < 20));
	printf("(a < 10) || (a > 20) : %d\n", (a < 10) || (a > 20));
	printf("!(a >= 30) : %d\n", !(a >= 30));

	return 0;
}
#endif

/***********************************************************/
// [4-확인2] 평균을 구해보자
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int k, e, m, tot;
	double avg ;

	printf("세 과목의 점수 : ");
	scanf("%d %d %d", &k, &e, &m);
	tot = k + e + m;
	avg = tot / 3;

	printf("총점수 : %d", tot);
	printf("평균 : %d\n", avg);

	return 0;
}
#endif

/***********************************************************/
// [4-8] 형 변환 연산자가 필요한 경우
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a = 20, b = 3;
	// a / b => 6.6666
	// 5.0 / 2.0 => 2.51
	// 실수 / 정수 -> 실수
	// double / int -> double
	double result = (double)a / b;
	printf("%lf\n", result);

	int answer = (int)result; //6.66667 
	printf("%d\n", answer);

	// 형 변환 
	// 자동 형 변환 : 컴파일 시 자료형을 컴파일러가 알아서 바꿈
	// 묵시적(암시적) 형 변환
	// Implicit Type Casting
	 
	// 명시적 형 변환 : (자료형)값
	// Explicit Type Casting

	return 0;
}
#endif

/***********************************************************/
// [4-9] sizeof 연산자의 사용 예
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a = 10;
	double b = 3.14;

	printf("int형 변수의 크기 : %d\n", sizeof(a)); // 4byte
	printf("double형 변수의 크기 : %d\n", sizeof(b)); // 8
	printf("정수형 상수의 크기 : %d\n", sizeof(100)); // 4
	printf("수식의 결과값의 크기 : %d\n", sizeof(1.5 + 3.4)); // 8
	printf("char형 자료의 크기 : %d\n", sizeof(char)); // 1 (char자체는 1)
	

	return 0;
}
#endif

/***********************************************************/
// [4-10] 복합대입 연산자
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int age = 20;
	// 내년 생일이 되어서
	// age 한 살 증가
	//age = age + 1; 
	age += 1;

	int salary = 100000000;
	// 월급을 10% 인상해라
	//salary = salary * 1.1;
	salary *= 1.1;



	return 0;
}
#endif

/***********************************************************/
// [4-11] 콤마 연산자
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a = 10, b = 20;
	int result;

	result = (++a, ++b); // = 는 연산 순위 거의 최하위 근데 , 는 더 하위임
	//for문에서 사용 
	printf("%d\n", result);
	printf("%d\n", a);

	return 0;
}
#endif

/***********************************************************/
// [4-12] 조건 연산자
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	//내일의 점심 메뉴 골라보자
	int menu = 54;

	// menu가 짝수라면
	// 짜장면
	// 홀수라면
	// 짬뽕
	// 조건 연산자 : C언어에서 유일한 삼항 연산자
	// (조건식) ? 실행문장1 : 실행문장2
	// 조건식 : 논리결과!! (1 또는 0)
	// 1. 1 또는 0
	// 2. 관계 연산자 ( >, >=, <, <=, ==, !=)
	// 3. 논리 연산자 (&&, ||, !)
	int lunch_menu = menu % 2 == 0 ? 1 : 0;
	// 1 : 짬뽕
	// 0 : 짜장
	printf("내일의 점심 메뉴 : %d\n", lunch_menu);

	return 0;
}
#endif

/***********************************************************/
// [4-12-큰 값] 큰 값을 구하자
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	//사용자로부터 두 정수를 입력 받아
	// A, B에 저장하자
	// 다음과 같이 출력
	// 큰 수 : ??
	// 만약 A가 10, Brk 20이 -> 큰수 : 20

	int A, B;
	scanf("%d %d", &A, &B);

	int large_number = A > B ? A : B; 
	printf("큰 수 : %d\n", large_number);

	
	return 0;
}
#endif

/***********************************************************/
// [4-12-절댓값] 절댓값을 구해보자
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	// 사용자가 입력한 정수의
	// 절댓값을 출력하자
	int a;
	scanf("%d", &a);
	// 사용자가 10 입력하면
	// 절댓값 : 10
	// 사용자가 -10 입력하면
	// 절댓값 : -10
	int result = a > 0 ? a : -a;
	printf("절댓값 : %d\n", result);

	return 0;
}
#endif

// 04月10日(木) #3
/***********************************************************/
// [4-13] 비트 연산식의 결과
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a = 10;						 // 0000,0000 0000,0000 0000,0000 0000,1010
	int b = 12;						 // 0000,0000 0000,0000 0000,0000 0000,1100

	printf("a & b : %d\n", a & b);   // 0000,0000 0000,0000 0000,0000 0000,1000
	printf("a ^ b : %d\n", a ^ b);	 // 0000,0000 0000,0000 0000,0000 0000,0110 
	// ^ : 두 논리가 다를 때 참
	printf("a | b : %d\n", a | b);	 // 0000,0000 0000,0000 0000,0000 0000,1110
	printf("~a : %d\n", ~a);		 // 1111,1111 1111,1111 1111,1111 1111,0011
	// ~ : 부정 연산자 1->0, 0->1
	printf("a << 1 : %d\n", a << 1); // 0000,0000 0000,0000 0000,0000 0001,0100
	printf("a >> 2 : %d\n", a >> 2); // 0000,0000 0000,0000 0000,0000 0000,0010

	// a = a*2
	// a *= 2
	// a << 1 <- 젤빠름

	// a = a << 2 
	// a <<= 2  복합대입연산자로 사용가능 단 비트 부정 연산자(~)는 단항 연산자로 사용 불가능.

	// -11 >> 1
	// ~a >> 1
	// ~a : 1
	// -11 : 00000000 00000000 00000000 00001011
	//     : 11111111 11111111 11111111 11110101
	//     : 11111111 11111111 11111111 11111010
	//음수 : 00000000 00000000 00000000 00000110 : 6


	return 0;
}
#endif

/***********************************************************/
// [4-14] 연산자 우선순위와 연산 방향
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	printf("10 / 5 * 2 = %d\n", 10 / 5 * 2); // 4
	printf("10 > 5 && 10 != 5 : %d\n", 10 > 5 && 10 != 5); //1
	printf("10 %% 3 == 0 : %d\n", 10 % 3 == 0); //


	return 0;
}
#endif

/***********************************************************/
// [5-1] 성인 여부 판단하기
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int age;
	
	printf("나이 입력 : ");
	scanf("%d", &age);

	if (age >= 20)
	{
		printf("성인입니다~\n");
	}

	printf("프로그램 종료."); //뒤에 이런거 써주면 if문 끝났는지 알 수 있음.

	return 0;
}
#endif

/***********************************************************/
// [5-2] 공배수 출력하기
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int num;

	printf("정수 입력 : ");
	scanf("%d", &num);

	if (num % 3 == 0 && num % 5 == 0) // num % 15 == 0 <- 값은 같지만 권장X &로 문제 의도에 맞게 하는게 좋다~
		printf("3과 5의 배수입니다.\n");

	printf("프로그램 종료."); //뒤에 이런거 써주면 if문 끝났는지 알 수 있음.

	return 0;
}
#endif

/***********************************************************/
// [5-3] 성인 및 미성년자 여부 판단하기
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int age;

	printf("나이 입력 : ");
	scanf("%d", &age);

	if (age >= 20)
	{
		printf("성인 입니다.\n");
	}
	else
	{
		printf("애들은 가라~\n");
	}

	return 0;
}
#endif

/***********************************************************/
// [5-4] 홀수 짝수 여부 판단하기
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int num;

	printf("숫자 입력 : ");
	scanf("%d", &num);

	if (num % 2 == 0)
	{
		printf("짝수 입니다.");
	}
	else
	{
		printf("홀수 입니다.");
	}

	return 0;
}
#endif

/***********************************************************/
// [5-5] 마트 계산대 프로그램
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int price, num, dc;

	printf("개수 입력 : ");
	scanf("%d", &num);

	// rate = 1-0.1;
	// money = num * price * rate -> 이렇게 갔을때 실수에서 정수로 자동 형변환
	price = 10000 * num;
	dc = price * 0.1;

	if (num >= 11)
	{
		price -= dc;
		printf("%d원 입니다.\n", price);
	}
	else
	{
		printf("%d원 입니다.\n", price);
	}

	return 0;
}
#endif

/***********************************************************/
// [5-6] title
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a;

	printf("성적 입력 : ");
	scanf("%d", &a);

	if (a >= 90)
		printf("A");
	else if (a >= 80)
		printf("B");
	else if (a >= 70)
		printf("C");
	else if (a >= 60)
		printf("D");
	else
		printf("F");

	return 0;
}
#endif

/***********************************************************/
// [5-7] 마트 계산 프로그램 확장
/***********************************************************/

// 할인 방식 잘못 짠듯 수정필요!!!!!
#if 0
#include <stdio.h>

int main(void)
{
	int price, num, dc, member, dc_member;

	printf("개수 입력 : ");
	scanf("%d", &num);
	printf("회원 여부(회원 :1,비회원 : 0) : ");
	scanf("%d", &member);

	// rate = 1-0.1;
	// money = num * price * rate -> 이렇게 갔을때 실수에서 정수로 자동 형변환
	price = 10000 * num;
	dc = price * 0.1;
	dc_member = price * 0.2;

	if (num >= 11 && member == 1)
	{
		price -= dc_member;

		printf("%d원 입니다.", price);
	}
	else if(num >= 11 || member == 1)
	{
		price -= dc;

		printf("%d원 입니다.", price);
	}
	else
	{
		printf("%d원 입니다.", price);
	}


	return 0;
}
#endif

/***********************************************************/
// [5-7.5] switch란?
/***********************************************************/

//switch (상수식)
//{
//    case 값:
//        실행문장1;
//    case 값:
//        실행문장2;
//}
#if 0
#include <stdio.h>

int main(void)
{
	int month = 4;

	switch (month)
	{
	case 4:
		printf("봄\n");
		break; // 해당 블럭 탈출
	case 6:
		printf("여름\n");
		break;
	}

	return 0;
}
#endif

/***********************************************************/
// [5-8] 상금 지급 프로그램
/***********************************************************/

#if 0
#include <stdio.h>
//if else 보다 switch가 연산이 약간 더 빠르다~
int main(void)
{
	int rank;

	printf("등수 입력 : ");
	scanf("%d", &rank);

	// printf(" %d만원\n", -100 * rank + 400); 
	// 수학적 지식으로 이렇게 써도 되지만 이건 내가 계산을 했기 때문에 좋은 프로그래밍이 아님
	// 수학적 지식이 있으면 효율적인 코드 작성 가능함
	switch(rank)
	{
	case 1:
		printf("300만원\n");
		break; //특정상황에 안써도 되지만 기본적으로 작성해야함
	case 2:
		printf("200만원\n");
		break;
	case 3:
		printf("100만원\n");
		break;
	}
	return 0;
}
#endif

/***********************************************************/
// [5-확인] 자판기 프로그램
/***********************************************************/
// 내가 푼거아님 다시 확인 필요
#if 0
#include <stdio.h>

int main(void)
{
	printf("금액을 입력하세요 : ");
	int money;
	scanf("%d", &money);
	printf("메뉴를 고르세요\n");
	printf("[1]아침햇살(700원) [2]솔의눈(1000원) [3]데자와(500원) : ");
	int menu;
	scanf("%d", &menu);
	int change; // 잔돈을 저장하는 변수
	int money_1000; // 1000원짜리 개수
	int money_500; // 500원짜리 개수
	int money_100; // 100원짜리 개수

	int price; // 각 메뉴의 가격
	switch (menu)
	{
	case 1:
		price = 700; // 아침햇살 700원
		break;
	case 2:
		price = 1000; // 솔의눈 1000원 
		break;
	case 3:
		price = 500; // 데자와 500원
		break;
	}
	change = money - price; // 입력한 금액에서 해당 메뉴 가격 차감
	if (change < 0)
	{
		printf("돈이 부족해요ㅠㅠ");
		change = money; // 잔돈이 부족할 경우 감소하기 전 투입 금액 저장!!
	}
	printf("잔돈 : %d원\n", change);
	// change : 7800
	money_1000 = change / 1000;
	money_500 = change % 1000 / 500;
	money_100 = change % 500 / 100;
	printf("천원 : %d개, 오백원 : %d개, 백원 : %d개\n", money_1000, money_500, money_100);

	return 0;
}
#endif

/***********************************************************/
// [5-실전] 계산기 프로그램
/***********************************************************/
//내가 푼거 아님 다시 확인 필요
#if 0
#include <stdio.h>

int main(void)
{
	// 3 + 5 = 8
	// %d + %d = %d
	// 11/3
	int num1, num2;
	char operator;
	printf("사칙연산 입력(정수) : ");
	scanf("%d%c%d", &num1, &operator, &num2);

	if (operator == '+')
	{
		printf("%d%c%d=%d\n", num1, operator, num2, num1 + num2);
	}
	else if (operator == '-')
	{
		printf("%d%c%d=%d\n", num1, operator, num2, num1 - num2);
	}
	else if (operator == '*')
	{
		printf("%d%c%d=%d\n", num1, operator, num2, num1 * num2);
	}
	else if (operator == '/')
	{
		printf("%d%c%d=%d\n", num1, operator, num2, num1 / num2);
	}

	return 0;
}

#endif

/***********************************************************/
// [6-1] 자릿수 계산 프로그램
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int digits = 0; // 출력할 자릿수
	int num; // 입력받은 정수
	printf("정수 입력 : ");
	scanf("%d", &num);

	/*
	if (num % 10 != 0)
	{
		digits++;
		num /= 10;
	}

	if (num / 10 != 0)
	{
		digits++;
		num /= 10;
	}*/

	// 반복 횟수가 정해져 있지 않을 때 while문 사용
	// 반복 횟수가 정해져 잇을 때 for문 사용
	// (반드시는 아니고 권장)

	while (num != 0)
	{
		digits++;
		num /= 10;
	}
	printf("%d자리 정수입니다.", digits);

	return 0;
}
#endif

/***********************************************************/
// [6-2] 10보다 작은 값 입력 프로그램
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int num;
	printf("정수 입력 : ");
	scanf("%d", &num);
	// 바깥에도 한번 입력 받아야됨 -> 나중에 do while문에서 ~
	while (num < 10)
	{
		printf("정수 입력 : ");
		scanf("%d", &num);
	}
	printf("종료");

	return 0;
}
#endif

/***********************************************************/
// [6-3] 누적합 출력 프로그램
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	int num, sum = 0;
	printf("정수 입력 : ");
	scanf("%d", &num);
	sum += num;
	printf("누적 결과 : %d\n", sum);

	while (num != -1) 
	{
		
		printf("정수 입력 : ");
		scanf("%d", &num);
		sum += num;
		printf("누적 결과 : %d\n", sum);
	}

	return 0;
}
#endif

/***********************************************************/
// [6-4] for문 연습
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	// 1 ~ 10까지 출력
	int i;
	// for(초기식; 조건식; 증감식)
	for (i = 1; i <= 10; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (i = 21; i <= 57; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (i = 96; i >= 53;i--)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (i = 21; i <= 57; i++)
	{
		if (i % 2 != 0)
		{
			printf("%d ", i);
		}
	}
	printf("\n");

	for (i = 1; i <= 100;i++)
	{
		if (i % 3 == 0)
			printf("%d ", i);
	}
	printf("\n");

	for (i = 1; i <= 100;i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
			printf("%d ", i);
		/*
		 if (i % 3 == 0 && i % 5 == 0)
			{
				continue; // 더 이상 코드 진행 X 다음 증감식으로 바로 이동!
			}

		*/
	}
	printf("\n");

	for (i = 1; i <= 100;i++)
	{
		if (i % 3 != 0)
			printf("%d ", i);
	}
	printf("\n");

	return 0;
}
// for(int i = 1; ~ : ~ )
// 똑같은 i를 계속 써도 되는 이유 = 지역변수(Local variable)
// 한 지역 내에서 생성된 변수는
// 그 지역 내에서 쓰여지고 버려진다.
// 근데 굳이 for(int i = 1)이렇게 써야되나?
#endif

/***********************************************************/
// [6-5] 배수 출력하기
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int num, i;
	

	printf("자연수를 입력하세요 : ");
	scanf("%d", &num);
	for (i = 1; i <= 10; i++)
	{
		printf("%d ", num*i);
	}

	return 0;
}
#endif

/***********************************************************/
// [6-6] 구구단 출력하기
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int i;
	for (i = 1; i <= 9; i++)
	{
		printf("2 x %d = %d\n", i, 2 * i);
	}

	return 0;
}
#endif

/***********************************************************/
// [6-7] 약수 출력하기
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int num, i;
	printf("정수를 입력하세요 : ");
	scanf("%d", &num);

	for (i = 1; i <= num / 2; i++) 
		// 수학적 지식이 있을수록 효율적인 코드 설계 가능
		//제일 큰수/2 와 제일 큰수 사이에 수 없음
	{
		if (num % i == 0)
		{
			printf("%d ", i);
		}
	}
	printf("%d", num);

	return 0;
}
#endif

/***********************************************************/
// [6-권장] 권장 규칙!! 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	//1 ~ 10
	int i;
	for (i = 7; i <= 16; i++)
	{
		printf("%d ", i - 6);
		i++; 
		// 변수를 내부에서 제어 -> 반복이 제 때 종료되어야 하는데
		// 의도와 달리 종료가 안되는 경우가 있음
		// 가능은 하지만 굉장히 강력하게 규제
	}
	// 초기식, 조건식 알기 어려움
	// 직관적이게 설계해야함

	return 0;
}
#endif

/***********************************************************/
// [6-유지보수] 누적합 do ~ while 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int sum = 0; //누적합 저장 변수
	int num;

	do
	{
		printf("정수 입력 : ");
		scanf("%d", &num);

		sum += num;

		printf("누적 합계 : %d\n", sum);
	} while (num != -1);

	return 0;
}
#endif

/***********************************************************/
// [6-많이써요] 무한 반복문
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	// 1을 무한히 출력
	int num, sum = 0;
	while (1)
	{
		printf("정수 입력 :");
		scanf("%d", &num);

		if (num == -1)
		{
			break;
		}

		sum += num;

		printf("누적 합계 : %d\n", sum);
	}

	return 0;
}
#endif

/***********************************************************/
// [6-8] 다이어트 관리 프로그램
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int current_weight; // 현재 몸무게
	int goal_weight; // 목표 몸무게
	int week; // 주차
	int loss_weight = 0; // 감량 몸무게

	printf("현재 몸무게 : ");
	scanf("%d", &current_weight);
	printf("목표 몸무게 : ");
	scanf("%d", &goal_weight);

	while (1)
	{
		week = 1;
		printf("%d주차 감량 몸무게 : ", week);
		scanf("%d", &loss_weight);
		current_weight -= loss_weight;
		week++;

		if (current_weight <= goal_weight)
		{
			break;
		}
	}
	printf("%dkg 달성 축하드립니다!!", goal_weight);

}
#endif

/***********************************************************/
// [6-9] 로그인 프로그램
/***********************************************************/
// 시간 나면 해보기
// ID PW 미리 지정하고 만족하면 성공 실패 시 while돌리기
#if 0
#include <stdio.h>
#include <string.h> //strcmp(문자열1, 문자열2)

int main(void)
{
   // 시간 나시면 해보셔요!!
   // 기본 자료형 
   // 정수형 : short, int, long, long long
   // 실수형 : float, double, long double
   // 문자형 : char
   // 관계 연산 (비교 연산)
   // 크니? 작니? 같니? 

   char fruit[20] = "banana";
   char fruit2[20] = "banana";
   if (fruit == fruit2) // 기본 자료형이 아니기 때문에 비교 불가
   {
      printf("같습니다"); 
   }
   // <string.h> 안에 strcmp()
   // 0 : 두 문자열이 같다

   printf("%d", strcmp(fruit, fruit2));

   char login_id[20] = "nayeho";
   char login_pw[20] = "1234";

   while(1)
   {
      char id[20], pw[20];
      printf("ID : ");
      scanf("%s", id);
      printf("PW : ");
      scanf("%s", pw);

      if (!strcmp(id, login_id) && !strcmp(pw, login_pw) == 1)
      {
         printf("로그인 성공");
         break;
      }
      else
      {
         printf("로그인 실패");
      }

   }
   return 0;
}

int main(void)
{
	// 시간 나시면 해보셔요!!
	// 기본 자료형 
	// 정수형 : short, int, long, long long
	// 실수형 : float, double, long double
	// 문자형 : char
	// 관계 연산 (비교 연산)
	// 크니? 작니? 같니? 

	char fruit[20] = "banana";
	char fruit2[20] = "banana";
	if (fruit == fruit2) // 기본 자료형이 아니기 때문에 비교 불가
	{
		printf("같습니다");
	}
	// <string.h> 안에 strcmp()
	// 0 : 두 문자열이 같다

	printf("%d", strcmp(fruit, fruit2));

	char login_id[20] = "nayeho";
	char login_pw[20] = "1234";

	while (1)
	{
		char id[20], pw[20];
		printf("ID : ");
		scanf("%s", id);
		printf("PW : ");
		scanf("%s", pw);

		if (!strcmp(id, login_id) && !strcmp(pw, login_pw) == 1)
		{
			printf("로그인 성공");
			break;
		}
		else
		{
			printf("로그인 실패");
		}

	}
	return 0;
}
#endif

/***********************************************************/
// [6-11] 별찍기 기초
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	// *****
	// *****
	// *****

	int i, j;

	for (i = 1;i <= 3;i++)
	{
		for (j = 1;j <= 5;j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
#endif

/***********************************************************/
// [6-13] 백준 별찍기 1
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int i, j;
	int n;
	scanf("%d", &n);

	for (i = 1;i <= n;i++)
	{
		for (j = 1;j <= i;j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
#endif

/***********************************************************/
// [6-14] 백준 별찍기 2
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int i, j;
	int n;
	scanf("%d", &n);

	for (i = 1;i <= n;i++)
	{
		for (j = 1; j <= n - i;j++)
		{
			printf(" ");
		}
		for (j = 1;j <= i;j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
#endif

