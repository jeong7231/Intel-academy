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
// [5-6] 학점 계산 프로그램
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

//04月11日(金) #3
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

/***********************************************************/
// [8-1] 배열의 선언과 사용
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int array[5]; // 4byte x 5 = 20byte 할당. 0 부터 출발

	array[0] = 10;
	array[1] = 20;
	array[2] = 30;
	array[3] = 40;
	array[4] = 50;

	// 배열 요소가 초기화 되어 있지 않다면
	// 배열이 초기화 되어 있지 않다면
	// 사용시 쓰레기 값 출력
	for (int i = 0;i < 5;i++) // i<=4 아니라 i<5로 쓰자~
	{
		printf("%d\n", array[i]);
	}
	


	return 0;
}
#endif

/***********************************************************/
// [8-2] 배열의 선언과 사용
/***********************************************************/

#if 0

#include <stdio.h>

int main(void)
{
	int array[5] = { 8,4,99,6,7 };
	printf("array에 들어있는 홀수는 ");

	// sizeof 연산자 활용!!
	// array[5] -> 20byte -> 20byte / 4 = 5
	// //sizeof(int) -> 4byte
	// sizeof(double) -> 8byte
	// sizeof(char) -> 1byte
	// 나중에 갱신해서 array[6]이 되면 5가 있었던 모든 부분을 바꿔야됨

	int length = sizeof(array) / sizeof(int) //array 배열 크기

	for (int i = 1; i < length; i++)
	{
		if (array[i] % 2 == 1) // (!(array[i] % 2)
		{
			printf("%d ", array[i]);
		}
	}
	printf(" 이다.");
	return 0;
}
#endif

/***********************************************************/
// [8-3] sizeof 연산자를 이용한 배열
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	int score[5];
	int sum = 0;
	double avg;

	int length = sizeof(score) / sizeof(int);

	for (int i = 0; i < length; i++)
	{
		printf("%d과목 성적을 입력하세요 : ", i);
		scanf("%d", &score[i]);
		sum += score[i];
	}
	avg = (double) sum / length;
	
	printf("총점 : %d, 평균 : %.1lf", sum, avg);

	return 0;
}
#endif

/***********************************************************/
// [8-4] char형 배열의 선언과 초기화
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	char fruit[6] = { 'a', 'p','p','l','e' };
	char fruit2[6] = "apple";

	for (int i = 0; i < 5; i++)
	{
		printf("%c", fruit[i]);
	}
	printf("\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%c", fruit2[i]);
	}
	printf("\n");

	//stirng으로 다루려면 끝에 NULL문자 표기 해야됨.
	//1 더 크게 만들어두면 남는칸 0(NULL)으로 초기화됨
	//1byte짜리라 넉넉하게 만들어도됨
	printf("%s\n", fruit);
	printf("%s\n", fruit2);


	char my_name[10];
	my_name[0] = 'j';
	my_name[1] = 't';
	my_name[2] = 'y';
	my_name[3] = '\0'; //NULL문자로 문자열의 끝을 알려줘야됨

	printf("%s\n", my_name);


	return 0;
}
#endif

/***********************************************************/
// [8-5] 문자열을 대입하는 strcpy 함수
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h> // strcpy()함수를 사용하기 위한 라이브러리

int main(void)
{
	char cat_name[100] = "이름을 지어주세요";
	
	//char fruit[100] = "apple";
	//printf("현재 과일 : %s\n", fruit);
	//// strcpy(이전문자열, 새로운 문자열)
	//strcpy(fruit, "banana");
	//printf("새로운 과일 : %s\n", fruit);
	printf("이름을 지어주세요 : ");

	char new_name[100];
	scanf("%s", new_name);

	strcpy(cat_name, new_name);

	printf("%s", cat_name);
	return 0;
}
#endif

/***********************************************************/
// [8-6] 띄어쓰기까지입력받자!!
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	char inputs[100];
	printf("내일의 점심 메뉴 입력 : ");
	gets(inputs); // 띄어쓰기, 탭 인식함

	puts(inputs);

	//printf("%s\n", inputs);
	return 0;
}
#endif

/***********************************************************/
// [8-도전] 대소문자 변환 프로그램
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h> // strlwr() 소문자로 바꾸는 함수!! 

int main(void)
{
	//char inputs[100];
	//printf("문장 입력 : ");
	//gets(inputs); // 띄어쓰기, 탭 인식함
	//
	//// inputs : "Hello World!!" 라면
	//// words[0] -> H
	//// words[1] -> e
	//// 'A' -> 65, 'a'->97
	//// 'A'~'z' 사이라면 ->대문자

	//int length = sizeof(inputs) / sizeof(char);
	//for (int i = 0; i < length; i++)
	//{
	//	if (inputs[i] >= 'A' && inputs[i] <= 'a')
	//	{
	//		inputs[i] += 32;
	//		//Capital 65~90 Small 97~122
	//	}
	//}
	//puts(inputs);

	char temp[100] = "HELLO WORLD!!";
	strlwr(temp);

	printf("%s\n", temp);
	//pragma로 지워야 실행되는 함수는 어지간하면 쓰지 않는게 좋다
	//필요하면 직접 구현하는게 좋음

	return 0;
}
#endif

/***********************************************************/
// [8-정렬] 기본 정렬
/***********************************************************/

#if 1
#include <stdio.h>

int main(void)
{
	// 정렬?? : 탐색을 손쉽게 하기 위해
	// 가장 큰 수는??
	// 모든 값 탐색 : 시퀀셜 서치
	// 오름차순 (Ascending sort) : 1 7 13 21 28 31
	// 내림차순 (Descending sort) : 

	// 1. 버블 정렬(Bubble sort)
	// 자리를 어떻게 바꿀 것인가??->치환(swap)

	//int num1 = 10;
	//int num2 = 20;

	//int temp;

	//temp = num1;
	//num1 = num2;
	//num2 = temp;

	int array[100];

	for (int j = 5;j > 0;j--)
	{
		for (int i = 0;i < 6;i++)
		{
			int temp;
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 6; i++)
	{
		printf("%d", array[i]);
	}
	
	return 0;
}
#endif
// 이어서 작성하기

//04月14日(月)
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

// 04月15日(火)
/***********************************************************/
// [10-1] 배열며에 정수 연산을 수행해 배열 요소 사용
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int ary[3]; //3칸 짜리 int형 배열 선언

	printf("%d\n", ary);

	printf("%d\n", &ary[0]);

	printf("%d\n", (ary + 1));

	ary[0] = 10;

	*(ary + 1) = 20;
	// *(ary + 3) = 20; <- 범위 벗어난 주소 사용 금지!!!!!!!

	for (int i = 0; i < 3; i++)
	{
		printf("%d 번째 요소 : %d\n", (i + 1), ary[i]);
	}
	
	return 0;
}
#endif

/***********************************************************/
// [10-2] 배열명 처럼 사용되는 포인터
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int ary[3];
	int* pa = &ary;

	*pa = 10;
	// 20을 배열 두 번재 요소(인덱스 1)에 할당!
	//ary[1] = 20;
	//*(ary + 1) = 20;
	//*(pa + 1) = 20;
	pa++;
	*pa = 20;

	pa++;
	*pa = 30;
	// 반복문 활용 가능


	for (int i = 0; i < 3; i++)
	{
		printf("%d번째 요소 : %d\n", i + 1, ary[i]);
	}

	printf("배열 전체의 길이 : %d\n", sizeof(ary));
	printf("포인터 하나의 길이 : %d\n", sizeof(pa)); //컴파일러 따라 4나올수도

	return 0;
}
#endif

/***********************************************************/
// [10-3] 포인터를 이용한 배열의 값 출력
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int ary[3] = { 10,20,30 };
	int* pa = ary;

	printf("배열의 값 : ");
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", *pa);
		
		// 후위니까 사용하고 증가시킴
		pa++;
		//++pa <- intdex1, index2, index? -> 3번 인덱스가 없어서 문제가 생길 수 있다.
		// 전위 증감은 쓰지마라~~!!!
		
		// pa는 첫번재 배열 요소의 주소를 가리키고 있다. 
		// *pa 는 가리키는 요소의 값을 보고있다. 
	}
	// 그럼에도 불구하고 후위 증감 연산자 사용 시!!!!
	// 주소 값의 범위를 확인 하여 범위를 벗어났는지 체크할것!!!!!!
	// 걍 전위 쓰지 마라
	printf("\n", *pa);

	pa = ary; // 재할당 후 다시 사용 가능
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", *pa);
		pa++;
	}

	return 0;
}
#endif

/***********************************************************/
// [10-4] 포인터의 뺄셈과 관계 연산
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int ary[5] = { 20,20,30,40,50 };
	int* pa = ary;
	int* pb = ary + 3;

	// print *pa -> 10
	// print *pb -> 40

	pa++;
	printf("pb-pa : %u\n", pb - pa); //2칸 차이나고 있다~

	// 두 포인트 중
	// 더 앞에 있는(인덱스가 작은) 요소 출력!!

	if (pa < pb)
	{
		printf("%d\n", *pa);
	}
	else
	{
		printf("%d\n", *pb);
	}

	return 0;
}
#endif

/***********************************************************/
// [10-5] 배열을 처리하는 함수
/***********************************************************/

#if 0
#include <stdio.h>

void print_ary(int* pa)

int main(void)
{
	int ary[5] = { 10,20,30,40,50 };
	print_ary(ary);

	return 0;
}

void print_ary(int* pa)
{
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", pa[i]);
	}
}
#endif

/***********************************************************/
// [10-6] 크기가 다른 배열을 처리하는 함수
/***********************************************************/

#if 0
#include <stdio.h>

void print_ary(int* pa, int size);

int main(void)
{
	int ary[5] = { 10,20,30,40,50 };
	int ary2[7] = { 10,20,30,40,50,60,70 };

	print_ary(ary, 5);
	print_ary(ary2, 7);

	return 0;
}


void print_ary(int* pa, int size)
{ 
	// 배열의 주소를 담고 있는 포인터 pa를 활용하여
	// 모든 배열의 요소를
	// 예) 10 20 30 40 50으로 출력
	 
	
	//void print_ary(int* pa)
	//int size = pa; <- c언어에서 포인터만 가지고 배열의 크기를 볼 수 있는 방법 없음

	for (int i = 0; i < size; i++)
	{
		printf("%d ", pa[i]);
	}
	printf("\n");
}
#endif

/***********************************************************/
// [10-7] 배열의 값을 입력하는 함수
/***********************************************************/

#if 0
#include <stdio.h>

void input_ary(int* pa, int size);
void find_max(int* pa, int size);
void print_ary(int ary[], int size);

int main(void)
{
	// 1. 배열에 값을 입력하는 input_ary()
	// input_ary(ary, 5);
	// 총 5번의 입력 발동
	// 예0 10 20 30 40 50이 들어오면
	// ary[0] = 10,... ary[4] = 50
	int ary[5];
	input_ary(ary, sizeof(ary) / sizeof(int)); //5대신 sizeof(ary) / sizeof(int)

	print_ary(ary, 5);

	// 배열의 최댓값을 찾아 출력하는 함수
	// find_max(ary, 5)
	// 배열의 최댓값 : 50
	find_max(ary, 5);

	
	
	
	return 0;
}

void input_ary(int *pa, int size)
{
	printf("정수 5개 입력 : ");
   // 총 5번의 입력 값을 pa에 대입!!
   for (int i = 0; i < size; i++)
   {
      scanf("%d", &pa[i]);
   }
}
void find_max(int* pa, int size)
{
	int max = pa[0];// 배열의 첫 요소를 값으로 정해주자

	for (int i = 0; i < size; i++)
	{
		if (pa[i] > max)
		{
			max = pa[i];
		}
	}
	printf("배열의 최댓값 : %d\n", max);
}

void print_ary(int ary[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", ary[i]);
	}
	printf("\n");
}

#endif

/***********************************************************/
// [10-도전] 로또 번호 생성 프로그램
/***********************************************************/

#if 0
#include <stdio.h>  
#include <time.h>   // time()
#include <stdlib.h> // rand(), srand()

void print_lotto(int* pa, int size);
void input_lotto(int* pa, int size);

int main(void)
{
	// 도전 문제 : 6개의 정수를 입력 ( 1 ~ 45 )
	int lotto[6];

	input_lotto(lotto, 6);
	print_lotto(lotto, 6);

	return 0;
}
void input_lotto(int* pa, int size)
{
	srand(time(NULL)); // 현재 시각을 통해 시드 랜덤!!
	for (int i = 0; i < size; i++)
	{
		// pa[i] = 랜덤으로 1 ~ 45까지 추출
		pa[i] = rand() % 45 + 1;
		// 로또 번호 입력 로직 시작
		/*printf("%d번째 로또 번호 입력 : ", (i + 1));
		scanf("%d", &pa[i]);*/
		// 로또 번호 입력 로직 끝

		for (int j = 0; j < i; j++)
		{
			// pa[3]은 pa[0], pa[1], pa[2]
			if (pa[i] == pa[j])
			{
				printf("중복입니다\n");
				// 다시 뽑는 로직!!
				// 현재 상황에서는
				// pa[i + 1]을 뽑게 됨
				// 왜? 증감식에 i++
				i--;
				break;
			}
		}
	}
}

void print_lotto(int* pa, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", pa[i]);
	}
	printf("\n");
}

#endif

/***********************************************************/
// [10-정렬] 정렬 알고리즘
/***********************************************************/

#if 0
#include <stdio.h>

void print_array(int* pa, int size);
void bubble_sort(int* pa, int size);
void swap(int* pa, int* pb);
void selecton_sort(int* pa, int size);
void binary_search(int* pa, int size, int search);

int main(void)
{
	int array[10] = { 1, 32, 19, 27, 23, 20, 15, 96, 25, 37 };
	int size = sizeof(array) / sizeof(int); // 10
	printf("배열 원본 : ");
	print_array(array, size); // 1 32 19 27 23
	//bubble_sort(array, size); // 버블정렬(오름차순)
	//printf("버블 정렬 후 : ");
	//print_array(array, size); // 1 19 23 27 32
	selecton_sort(array, size); // 선택정렬(오름차순)
	printf("선택 정렬 후 : ");
	print_array(array, size); //  1 15 19 20 23 25 27 32 37 96
	int search = 19;
	binary_search(array, size, search); // 찾고자 하는 23은 index 3에 있습니다

	return 0;
}
void print_array(int* pa, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", pa[i]);
	}
	printf("\n");
}
void swap(int* pa, int* pb)
{
	int temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}
void bubble_sort(int* pa, int size)
{
	for (int j = size - 1; j > 0; j--)
	{
		for (int i = 0; i < j; i++)
		{
			if (pa[i] > pa[i + 1]) swap(&pa[i], &pa[i + 1]);
		}
	}
}
void selecton_sort(int* pa, int size)
{
	// 선택정렬
	// 버블정렬의 단점을 보완
	// cycle당 최대 치환 1번
	// 1 32 19 27 23
	int max;
	int max_index;
	for (int j = 0; j < size - 1; j++)
	{
		max = pa[0];
		max_index = 0;
		for (int i = 0; i < size - j; i++)
		{
			if (pa[i] > max)
			{
				max = pa[i];
				max_index = i;
			}
		}
		swap(&pa[max_index], &pa[size - (j + 1)]);
	}
}
void binary_search(int* pa, int size, int search)
{
	// 이진탐색
	int low_index = 0; // 0
	int high_index = size - 1; // 9
	int mid_index = (low_index + high_index) / 2; // 4

	while (1)
	{
		// 23       >      19
		if (pa[mid_index] > search)
		{
			// low_index는 그대로
			high_index = mid_index - 1;
			mid_index = (low_index + high_index) / 2;
		}
		else if (pa[mid_index] < search)
		{
			// high_index는 그대로
			low_index = mid_index + 1;
			mid_index = (low_index + high_index) / 2;
		}
		else
		{
			printf("찾고자 하는 %d은 index %d에 있습니다", search, mid_index);
			break;
		}
	}
}


#endif

/***********************************************************/
// [11-1] 대문자를 소문자로 변경
/***********************************************************/

#if 0
#include <stdio.h>

char lowercase(char ch);

int main(void)
{
    printf("%c\n", lowercase('H')); // h

    return 0;
}

char lowercase(char ch)
{
    // 대문자가 아닌 경우 본래 문자 반환!!
    if (ch < 'A' || ch > 'Z')
    {
        return ch;
    }
    return ch + ('a' - 'A');
}

#endif

/***********************************************************/
// [11-2] 공백이나 제어 문자의 입력
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    // Hello World!! 입력받자
    while (1)
    {
        char ch;
        // scanf -> 문자 입력!! 문자열!! 정수!! 실수!!
        // 문자 : 1byte, 정수, 실수 -> 4, 8byte
        // 문자 전용 함수!!
        scanf("%c", &ch);
        if (ch == 10) break;
        printf("%c", ch);
    }
    printf("\n");

    while (1)
    {
        char ch;
        // scanf -> 문자 입력!! 문자열!! 정수!! 실수!!
        // 문자 : 1byte, 정수, 실수 -> 4, 8byte
        // 문자 전용 함수!!
        scanf("%c", &ch);
        if (ch == 10) break;
        printf("%c", ch);
    }
    return 0;
}
#endif

/***********************************************************/
// [11-3] getchar, putchar
/***********************************************************/
#if 0
#include <stdio.h>

int main(void)
{
    while (1)
    {
        int ch;
        ch = getchar();
        if (ch == 10) break;
        putchar(ch);
    }
    printf("\n");

    while (1)
    {
        int ch;
        ch = getchar();
        if (ch == 10) break;
        putchar(ch);
    }
    return 0;
}
#endif

/***********************************************************/
// [11-3] scanf에 공백??
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 5; i++)
    {
        char ch;
        scanf(" %c", &ch); // %앞에 공백 삽입 시 -> 화이트 스페이스 무시!!
        // 입력 값 : H e l l o
        // 입력 값 : H엔터e엔터l엔터l엔터o엔터
        // 입력 값 : H탭e탭l탭l탭o탭
        printf("%c\n", ch);
    }

    return 0;
}
#endif

/***********************************************************/
// [11-4] 버퍼를 사용한 문자 입력
/***********************************************************/
#if 0
#include <stdio.h>

int main(void)
{
    while (1)
    {
        // 엔터가 들어오기 전까지 입력!!
        // 엔터 들어올 시 break;
        char ch;
        scanf("%c", &ch);
        if (ch == '\n') break;
        printf("%c", ch);
    }

    return 0;
}
#endif


/***********************************************************/
// [11-5] 입력 문자의 아스키 코드를 출력하는 프로그램
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int result;
    char ch;

    while (1)
    {
        result = scanf("%c", &ch);
        if (result == EOF) break;
        printf("%d ", ch);
    }

    return 0;
}
#endif


/***********************************************************/
// [11-6] getchar 함수를 사용한 문자열 입력
/***********************************************************/

#if 0
#include <stdio.h>

// apple -> 문자열을 입력받는 함수!!
void my_getchar(char* str, int size);

int main(void)
{
    char str[7];
    my_getchar(str, 7);
    printf("입력한 문자열 : %s\n", str);

    return 0;
}
void my_getchar(char* str, int size)
{
    int i;
    for (i = 0; i < size - 1; i++)
    {
        // 사용자가 6글자 이상 입력할거다!!
        str[i] = getchar();
        if (str[i] == '\n')
        {
            break;
            i++;
        }
    }
    str[i] = '\0';
}
#endif


/***********************************************************/
// [11-7] 버퍼 초기화
/***********************************************************/
#if 0
#include <stdio.h>

int main(void)
{
    // scanf()과 getchar()는 buffer를 공유!!
    int num;
    printf("학번 입력 : ");
    scanf("%d", &num);
    printf("학점 입력 : ");

    // 입력 버퍼 사용 시 주의사항
    // 잘 모르겠으면 버퍼를 초기화하자!!
    getchar(); // 화이트 스페이스 꿀꺽!!

    int grage = getchar();
    printf("학번 : %d, 학점 : %c", num, grage);

    return 0;
}
#endif


/***********************************************************/
// [11-도전] 길이가 가장 긴 단어 찾기
/***********************************************************/
#if 0
#include <stdio.h>

int main(void)
{
    // 제약(Constraint)
    // 1. 문자열 입력하는 (scanf("%s")) 사용 ㄴㄴ
    // 2. string.h 쓰지 않기 -> 문자열 길이 strlen()

    int ch, max, len;
    max = -1;
    while (1)
    {
        // 1. 전체 입력의 종료를 판단
        // 2. 버퍼 비우기!!
        ch = getchar();
        if (ch == EOF) break;

        // 하나의 문자열을 입력!!
        len = 0;
        while (ch != '\n')
        {
            ch = getchar();
            printf("%d\n", ch);
            len++;
        }
        printf("해당 문자열의 길이 : %d\n", len);
        if (len > max) max = len;
    }
    printf("가장 긴 단어의 길이 : %d\n", max);

    return 0;
}
#endif


/***********************************************************/
// [12-1] 문자열은 문자열 배열??
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int array[5] = { 10, 20, 30, 40, 50 };
    int* pa = array;
    printf("%p\n", array);
    printf("%p\n", pa);

    char fruit[6] = { 'a', 'p', 'p', 'l', 'e', '\0' };
    char fruit2[6] = "apple";
    printf("%s\n", fruit);
    printf("%s\n", fruit2);

    char* pf = fruit;
    char* pf2 = fruit2;

    printf("%p\n", pf);
    printf("%p\n", pf2);

    return 0;
}
#endif


/***********************************************************/
// [12-2] 포인터로 문자열을 사용하는 방법
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    char drink[80] = "tejava";
    char* pd = drink;

    // *pd의 값이 널이 아닐 때 1, 널이면 0
    while (*pd) printf("%c", *(pd++));

    return 0;
}
#endif


/***********************************************************/
// [12-잠깐] 같은 문자열 상수??
/***********************************************************/
#if 0
#include <stdio.h>

int main(void)
{
    char fruit[6] = { 'a', 'p', 'p', 'l', 'e', '\0' };
    char fruit2[6] = "apple";
    char fruit3[6] = "apple";

    printf("apple의 주소 : %p\n", "apple");
    printf("apple의 주소 : %p\n", "apple");

    printf("%p\n", fruit);
    printf("%p\n", fruit2);
    printf("%p\n", fruit3);

    char* pf = fruit;
    char* pf2 = fruit2;
    char* pf3 = fruit3;

    printf("%p\n", pf);
    printf("%p\n", pf2);
    printf("%p\n", pf3);

    return 0;
}
#endif


/***********************************************************/
// [12-3] scanf 함수를 사용한 문자열 입력
/***********************************************************/
#if 0
#include <stdio.h>

int main(void)
{
    char str[80];

    printf("문자열 입력 : ");
    scanf("%s", str);
    printf("%s\n", str);
    scanf("%s", str);
    printf("%s\n", str);


    return 0;
}
#endif


/***********************************************************/
// [12-4] gets 함수로 한 줄의 문자열 입력
/***********************************************************/
#if 0
#include <stdio.h>

int main(void)
{
    char str[80];
    printf("문자열 입력 : ");
    gets(str); // \t, 공백 입력 가능!!
    printf("%s\n", str);

    return 0;
}
#endif


/***********************************************************/
// [12-5] gets의 안정성 보장을 위한 fgets
/***********************************************************/
#if 0
#include <stdio.h>
#include <string.h> // strlen()

int main(void)
{
    char str[80];
    printf("문자열 입력 : ");
    fgets(str, sizeof(str), stdin); // 키보드로 입력하겠다!!
    // fgets로 입력 받을 때 문자열 길이는 
    // strlen() - 1
    printf("문자열 길이 : %d\n", strlen(str) - 1);
    // 문자열을 제외한 자료구조 배열에서는
    // 배열의 요소 개수를 sizeof(배열명) / sizeof(자료형)
    printf("문자열 길이 2 : %d\n", sizeof("apple") - 1);

    printf("입력한 문자열 : %s\n", str);

    return 0;
}
#endif


/***********************************************************/
// [12-6] 개행 문자로 인해 get 함수가 입력 안되는 경우
/***********************************************************/
#if 0
#include <stdio.h>

int main(void)
{
    int age;
    char name[20];
    printf("나이 입력 : ");
    scanf("%d", &age);

    printf("이름 입력 : ");
    fgetc(stdin);
    gets(name);

    printf("나이 : %d, 이름 : %s\n", age, name);

    return 0;
}
#endif


/***********************************************************/
// [12-7] 문자열을 출력하는 puts와 fputs함수
/***********************************************************/
#if 0
#include <stdio.h>
int main(void)
{
    char str[80] = "apple juice";
    char* ps = "banana";

    // puts -> 자동 줄바꿈
    // fputs -> 자동 줄바꿈 X

    puts(str);
    puts(ps);

    fputs(str, stdout); // 모니터를 통해 표준출력!!
    fputs(ps, stdout);

    return 0;
}
#endif


/***********************************************************/
// [12-직접] gets 함수 구현해보기!!
/***********************************************************/
#if 0
#include <stdio.h>

int main(void)
{
    char str[20]; // "apple" 값을 입력!!
    // getchar() 함수를 활용해 gets() 구현!!
    // getchar() -> 문자 하나하나 입력!!
    int ch;
    char* ps = str;
    while (1)
    {
        ch = getchar();
        *ps++ = ch;
        if (ch == '\n') break;
    }
    *ps = '\0';

    printf("%s", str); // apple 출력!!

    return 0;
}
#endif

/***********************************************************/
// [12-8] 문자열을 대입하는 strcpy 함수
/***********************************************************/
#if 0
#include <stdio.h>
#include <string.h> // strcpy()

int main(void)
{
    char str[80] = "strawberry";
    // str을 "banana"로 바꾸시오
    // strcpy(복사할 곳, 복사할 내용);
    strcpy(str, "banana");
    printf("%s\n", str);

    char* ps = str;
    ps = "kiwi";
    printf("%s\n", ps);
    printf("%s\n", str); // banana

    return 0;
}
#endif


/***********************************************************/
// [12-9] n개의 문자열을 복사하는 strncpy
/***********************************************************/
#if 0
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[80] = "strawberry";
    strncpy(str, "mango", 5);

    char* ps = "chocolate";
    strncpy(str, ps, 5);

    char str2[80] = "melon_top_100";
    strncpy(str, str2, 5);

    printf("%s\n", str);

    return 0;
}
#endif


/***********************************************************/
// [12-8-직접구현] strcpy
/***********************************************************/
#if 0
#include <stdio.h>

// d: destination, s : source
char* my_strcpy(char* pd, char* ps);

int main(void)
{
    char str[80] = "strawberry";
    printf("바꾸기 전 문자열 : %s\n", str); // strawberry
    my_strcpy(str, "mango");

    printf("바꾼 후 문자열 : %s\n", str); // mango
    return 0;
}
char* my_strcpy(char* pd, char* ps)
{
    char* po;
    po = pd;

    while (*ps) *po++ = *ps++;
    *po = '\0';
    return po;
}

#endif


/***********************************************************/
// [12-10] 문자열을 연결하는 strcat()
/***********************************************************/
#if 0
#include <stdio.h>
#include <string.h> // strcat()
int main(void)
{
    char str[80] = "straw";
    // strcat(연결할 장소, 연결 내용);
    strcat(str, "berry");
    printf("%s\n", str); // strawberry
    char* pi = " ice-cream";
    strcat(str, pi);
    printf("%s\n", str); // strawberry ice-cream

    char str2[80] = "cake dessert yogurt";
    strncat(str, str2, 4);
    printf("%s\n", str); // strawberry ice-creamcake

    return 0;
}
#endif


/***********************************************************/
// [12-10-직접구현] 나만의 my_strcat() 만들기
/***********************************************************/
#if 0
#include <stdio.h>

char* my_strcat(char* pd, char* ps);

int main(void)
{
    char str[80] = "straw";
    my_strcat(str, "berry");
    printf("%s\n", str); // strawberry

    return 0;
}
char* my_strcat(char* pd, char* ps)
{
    char* po = pd;
    while (*po)   po++;
    while (*ps) *po++ = *ps++;
    *po = '\0';
    // 안 넣어도 동하는 이유 : 초기화된 문자열은 크기만큼 \0로 가득 차 있다
    return po;
}

#endif


/***********************************************************/
// [12-11] 문자열 길이 strlen()
/***********************************************************/
#if 0
#include <stdio.h>
#include <string.h> // strlen()
int main(void)
{
    char str1[80], str2[80];
    printf("두 과일 입력(과일1 과일2) : ");
    scanf("%s %s", str1, str2);

    // strlen(문자열) -> 문자열의 길이
    if (strlen(str1) > strlen(str2))
    {
        printf("첫 번째 과일이 더 깁니다.\n");
    }
    else
    {
        printf("두 번째 과일이 더 깁니다.\n");
    }
    printf("첫 번째 과일 : %s\n", str1);
    printf("두 번째 과일 : %s\n", str2);
    return 0;
}
#endif

/***********************************************************/
// [12-11-직접] 나만의 my_strlen() 만들기
/***********************************************************/

#if 0
#include <stdio.h>

int my_strlen(char* str);

int main(void)
{
    char str1[80], str2[80];
    printf("두 과일 입력(과일1 과일2) : ");
    scanf("%s %s", str1, str2);

    if (my_strlen(str1) > my_strlen(str2))
    {
        printf("첫 번째 과일이 더 깁니다.\n");
    }
    else
    {
        printf("두 번째 과일이 더 깁니다.\n");
    }
    printf("첫 번째 과일 : %s\n", str1);
    printf("두 번째 과일 : %s\n", str2);

    return 0;
}
int my_strlen(char* str)
{
    int length = 0;
    char* po = str;
    while (*po++) length++;
    return length;
}

#endif

/***********************************************************/
// [12-12] strcmp 함수를 사용한 문자열 비교 
/***********************************************************/
#if 0
#include <stdio.h>
#include <string.h> // strcmp(), strncmp()
int main(void)
{
    char str1[80] = "pear";
    char str2[80] = "peach";
    //int result = strncmp(str1, str2, 3);
    int result = strcmp(str1, str2);
    switch (result)
    {
    case 1: printf("%s이 사전에 나중에 나옵니다.\n", str1);
        break;
    case -1: printf("%s이 사전에 나중에 나옵니다.\n", str2);
        break;
    case 0: printf("문자열이 동일합니다.\n");
        break;
    default: printf("잘못 입력하셨습니다.\n");
        break;
    }
    return 0;
}
#endif
/***********************************************************/
// [12-12] 나만의 my_strcmp() 만들기
/***********************************************************/
#if 0
#include <stdio.h>

int my_strcmp(char* str1, char* str2);

int main(void)
{
    // 모두 소문자만 비교!!
    char str1[80] = "pear";a
    char str2[80] = "peach";
    int result = my_strcmp(str1, str2);
    switch (result)
    {
    case 1: printf("%s이 사전에 나중에 나옵니다.\n", str1);
        break;
    case -1: printf("%s이 사전에 나중에 나옵니다.\n", str2);
        break;
    case 0: printf("문자열이 동일합니다.\n");
        break;
    default: printf("잘못 입력하셨습니다.\n");
        break;
    }

    return 0;
}
int my_strcmp(char* str1, char* str2)
{
    char* p1 = str1;
    char* p2 = str2;

    while ((*p1 == *p2) && ((*p1 != '\0')))
    {
        p1++;
        p2++;
    }
    if (*p1 > *p2) return 1;
    else if (*p1 < *p2) return -1;
    else return 0;
}


#endif


/***********************************************************/
// [12-추가] 문자 개수 찾기
/***********************************************************/

#if 1
#include <stdio.h>

int find_char(char* str, char ch);

int main(void)
{
    printf("%d\n", find_char("Hello", 'H'));

    return 0;
}
int find_char(char* str, char ch)
{
    // str : "Hello"
    // ch : 'H'
    int count = 0;
    char* po = str;
    while (*po)
    {
        if (*po == ch) count++;
        po++;
    }
    return count;
}


#endif

// 4月16日(水)
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

/***********************************************************/
// [14-0] 2차원 배열 사용 이유
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	// 자료구조 -> 배열
	
	// 국 영 수 과
	int score1[4] = { 10,20,30,40 };
	int score2[4] = { 20,30,40,50 };
	int score3[4] = { 30,40,50,60 };

	// 전체 국어 점수의 총합
	int total_kor = score1[0] + score2[0] + score3[0];

	int scores[3][4] = {score1, score2, score3};
	// 첫 번째 사람의 영어 점수 -> score[1]
	// scores[0][1]
	return 0;
}
#endif

// 이거 왜 안됨? 다시 확인해보기 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
/***********************************************************/
// [14-1] 네 과목의 총점과 평균 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	// 국 영 수 과
	int scores[3][4] = {
		{72, 80, 95, 60}, // 첫 번째 사람의 각 과목 점수
		{68, 98, 83, 90}, // 두 번째 사람의 각 과목 점수
		{75, 72, 84, 90}, // 세 번째 사람의 각 과목 점수
	};
	// 두 번째 사람의 3번 과목 -> scores[1][2]
	
	// 첫 번째 사람의 총점 :
	// 두 번째 사람의 총점 : 
	// 세 번째 사람의 총점 : 
	int total[3] = { 0 };
	double avg[3] = { 0 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			total[i] += scores[i][j];
			avg[i] = (double)(total[j] / 4);
		}
		
		printf("%d번째 사람의 총점 : %d\n", i + 1, total[i]);
		printf("%d번째 사람의 평균 : %.lf점\n", i + 1, avg[i]);
	}




	return 0;
}
#endif

/***********************************************************/
// [14-1] 네 과목의 총점과 평균 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	// 국 영 수 과
	int scores[3][4] = {
		{72, 80, 95, 60}, // 첫 번째 사람의 각 과목 점수
		{68, 98, 83, 90}, // 두 번째 사람의 각 과목 점수
		{75, 72, 84, 90}, // 세 번째 사람의 각 과목 점수
	};
	// 두 번째 사람의 3번 과목 -> scores[1][2]

	// 첫 번째 사람의 총점 :
	// 두 번째 사람의 총점 : 
	// 세 번째 사람의 총점 : 
	int total;
	double avg;

	for (int j = 0; j < 3; j++)
	{
		total = 0;
		for (int i = 0; i < 4; i++)
		{
			total += scores[j][i];
		}
		avg = (double)total / 4;
		printf("%d번째 사람의 총점 : %d점\n", j + 1, total);
		printf("%d번째 사람의 평균 : %.1lf점\n", j + 1, avg);

		// 총 12개의 데이터
		// [3][4] : 3행 4열
		// 7번째 데이터의 행, 열의 index는 어떻게 되는가?
		// scores[1][2]
		// 1 ~ 4 -> 열 인덱스 0
		// 5 ~ 8 -> 열 인덱스 1
		// 9 ~ 12 -> 열 인덱스 2
		// 0 ~ 3 -> 1자리
		// 4 ~ 7 -> 2자리
		// like 4진수
		// 7 - 1 / 4
		 
		// 1번째 데이터 열 index -> 0
		// 2번째 데이터 열 index -> 1
		// 3번째 데이터 열 index -> 2
		// 4번째 데이터 열 index -> 3
		// 5번째 데이터 열 index -> 0
		// (7 - 1) % 4
		 
		// n번째 데이터의 행 index -> (n - 1) / 열의 개수
		// n번째 데이터의 열 index -> (n - 1) % 열의 개수

	}

	return 0;
}
#endif

/***********************************************************/
// [14-2] scanf를 통한 2차원 배열 초기화
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int scores[3][4];

	// 입력부
	for (int i = 0; i < 3; i++)
	{
		printf("%d번째 사람의 점수 입력 : ", i+1);
		for (int j = 0; j < 4; j++)
		{
			scanf("%d", &scores[i][j]);
		}
	}
	// 출력부
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%5d ", scores[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
#endif

/***********************************************************/
// [14-연습] 2차원 배열 부수기
/***********************************************************/

#if 0
#include <stdio.h>

void input_2d_array(int pa[5][5]);
void input_2d_array2(int pa[5][5]);

void print_2d_array(int* pa); // int pa[5][5] 도가능
void print_2d_array2(int* pa);
void print_2d_array3(int* pa);
void print_2d_array4(int* pa);
void print_2d_array5(int* pa);
void print_2d_array6(int* pa);
void print_2d_array7(int* pa);

int main(void)
{
	int array[5][5];

	int array2[10][3];
	// 행의 개수 : 10
	// 열의 개수 : 3
	// array2를 통해서 -> 10
	// array2 : 120byte
	// array2[0] : 12byte

	sizeof(array2); //120byte
	sizeof(array2[0]); // 12byte
	sizeof(int); // 4byte

	int row = sizeof(array2) / sizeof(array2[0]);
	int column = sizeof(array2[0]) / sizeof(int);

	//입력부1
	//input_2d_array(array);

	//입력부2
	input_2d_array2(array);

	//출력부1
	print_2d_array(array);

	printf("\n");

	//출력부2
	print_2d_array2(array);

	printf("\n");
	
	//출력부3
	print_2d_array3(array);

	printf("\n");

	//출력부4
	print_2d_array4(array);

	printf("\n");

	//출력부5
	print_2d_array5(array);

	printf("\n");

	//출력부6
	print_2d_array6(array);

	printf("\n");

	//출력부7
	print_2d_array7(array);

	return 0;
}

//입력
// 5x5에 1 ~ 25까지 데이터 추가!!
void input_2d_array(int pa[5][5])
{
	int count = 1;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			pa[i][j] = count++;
		}
	}
}
// 5x5에 21 ~ 45까지 데이터 추가!!
void input_2d_array2(int pa[5][5])
{
	int count = 21;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			pa[i][j] = count++;
		}
	}
}

//출력
void print_2d_array(int pa[5][5])
{
	// pointer
	// pa -> array[0]
	// pa + 1 -> array[1]
	// ((pa + 2) + 3) array[2][3]

	// 매개변수에 int pa[5][5]
	// 매개변수에 int pa[][5]
	// 매개변수에 int pa[]

	// pa는 5x5 2차원 배열
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%3d", pa[i][j]);
		}
		printf("\n");
	}
}

void print_2d_array2(int pa[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%3d", pa[j][i]);
		}
		printf("\n");
	}
}

void print_2d_array3(int pa[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 4; j >= 0; j--)
		{
			printf("%3d", pa[i][j]);
		}
		printf("\n");
	}
}

void print_2d_array4(int pa[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 4; j >= 0; j--)
		{
			printf("%3d", pa[j][i]);
		}
		printf("\n");
	}
}

void print_2d_array5(int pa[5][5])
{
	for (int i = 4; i >= 0; i--)
	{
		for (int j = 4; j >= 0; j--)
		{
			printf("%3d", pa[j][i]);
		}
		printf("\n");
	}
}

void print_2d_array6(int pa[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < 5; j++)
			{
				printf("%3d", pa[i][j]);
			}
			printf("\n");
		}
		else
		{
			for (int j = 4; j >= 0; j--)
			{
				printf("%3d", pa[i][j]);
			}
			printf("\n");
		}
	}


}

void print_2d_array7(int pa[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 0; j < 5; j++)
			{
				printf("%3d", pa[i][j]);
			}
			printf("\n");
		}
		else
		{
			for (int j = 4; j >= 0; j--)
			{
				printf("%3d", pa[i][j]);
			}
			printf("\n");
		}
	}


}

#endif

/***********************************************************/
// [14-3] 여러 마리의 동물을 입출력!!
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	char animal[5][20];
	int row = sizeof(animal) / sizeof(animal[0]); // 100 / 20 = 5

	for (int i = 0; i < row; i++)
	{
		scanf("%s", animal[i]);
	}

	for (int i = 0; i < row; i++)
	{
		printf("%s ", animal[i]);
	}

	return 0;
}
#endif

/***********************************************************/
// [14-4] 포인터 배열로 여러개의 문자열 출력
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	// 화장실갔다옴

	return 0;
}
#endif

/***********************************************************/
// [14-5] 포인터 배열을 통해 int 2차원도 1차원처럼 써보자
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int ary1[4] = { 10, 20, 30, 40 };
	int ary2[4] = { 11, 21, 31, 41 };
	int ary3[4] = { 12, 22, 32, 42 };

	int* pary[3] = { ary1, ary2, ary3 };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%3d", pary[i][j]);
		}
		printf("\n");
	}
	return 0;
}
#endif

/***********************************************************/
// [14-도전] 가로 세로의 합 구하기
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int array[5][6] = { 0 };
	
	// 입력부
	int count = 1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i < 4 && j < 5)
			{
				array[i][j] = count++;
			}
			
		}
	}
	// 논리부
	int total_row; // 행의 합 저장하는 변수
	int total_col; // 열으 합
	int i, j;
	// 1. 행의 합 구해서 대입!!
	for (i = 0; i < 5; i++)
	{
		total_row = 0;
		for (j = 0; j < 5; j++)
		{
			total_row += array[i][j];
		}
		array[i][j] = total_row;
	}
	// 2. 열의 합 구해서 대입!!
	for (i = 0; i < 5; i++)
	{
		total_col = 0;
		for (j = 0; j < 4; j++)
		{
			total_col += array[j][i];
		}
		array[j][i] = total_col;
	}
	// 3. 모든 값 더해서 array[4][5]에 대입
	int total = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++)
		{
			total += array[i][j];
		}
	}
	array[i][j] = total;

	// 출력부
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			printf("%3d", array[i][j]);
		}
		printf("\n");
	}
	return 0;
}
#endif

/***********************************************************/
// [백준-2738] 행렬 덧셈
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	int arr_a[100][100] = { 0 };
	for(int i=0; i<n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr_a[i][j]);
		}
	}

	int arr_b[100][100] = { 0 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr_b[i][j]);
		}
	}

	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", arr_a[i][j] + arr_b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
#endif

/***********************************************************/
// [백준-2566] 최댓값
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int array[9][9] = { 0 };
	//입력
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &array[i][j]);
		}
	}
	//최댓값
	int max = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if(max<array[i][j])
				max = array[i][j];
		}
	}
	printf("%d\n", max);

	// 두개 이상 일 시 위치 찾기
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (max == array[i][j])
				printf("%d %d\n", i+1, j+1);
		}
	}
	return 0;
}
#endif

// 4月17日(木)
/***********************************************************/
// [15-1] 이중 포인터
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a = 10;
	int* pi = &a;
	int** ppi = &pi;

	// pppi-> ppi의 주소 300번지
	// *pppi -> 200번지
	// **pppi -> 100번지
	// ***pppi -> 10
	int*** pppi = &ppi;

	printf("%d\n", sizeof(pi));

	printf("%d\n", a); // 10
	printf("%p\n", pi); // a의 주소 -> 100번지
	printf("%d\n", *pi); // 10 : 100번지를 찾아가서 값을 참조
	printf("%p\n", ppi); // pi의 주소 -> 200번지
	printf("%p\n", *ppi); //a의주소 -> 100번지
	printf("%d\n", **ppi); // 10 : (200번지를 찾아가서 값을 참조)번지를 찾아가서 값을 참조 -> 주소의 주소



	return 0;
}
#endif

/***********************************************************/
// [15-2] 이중 포인터를 활용한 문자열 교환
/***********************************************************/

#if 0
#include <stdio.h>

void swap_pointer(char** pa, char** pb);

int main(void)
{
	char* pa = "success";
	char* pb = "failure";

	printf("pa -> %s, pb -> %s\n", pa, pb);
	swap_pointer(&pa, &pb);
	printf("pa -> %s, pb -> %s\n", pa, pb);

	return 0;
}

void swap_pointer(char** ppa, char** ppb)
{
	// 이전에
	// int a, b; -> swap
	// swap(&a, &b)
	// swap(int *pa, int *pb);
	// int temp;
	int *temp;
	temp = *ppa;
	*ppa = *ppb;
	*ppb = temp;
	// 
	// *pa = temp;
	// *pb = *pa;
	// *pa = temp;
}
#endif

/***********************************************************/
// [15-3] 포인터 배열
/***********************************************************/

#if 0
#include <stdio.h>

void print_str(char** ppa, int size);

int main(void)
{	
	char* animal = { "dog" };
	printf("%s\n", animal);

	char* animals[4] = { "dog", "cat", "hippo", "snake" };
	// animals : 문자열(배열) 배열
	print_str(animals, 4);


	return 0;
}

void print_str(char** ppa, int size)
{
	for (int i = 0; i < 4; i++)
	{
		printf("%s\n", ppa[i]);
	}
}
#endif

/***********************************************************/
// [15-4] 배열의 주소??
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int array[5];
	printf("%u\n", array); // array의 주소 (0번 인덱스 주소)
	printf("%u\n", &array); // array의 주소값
	printf("%u\n", array + 1); // 1번 인덱스의 주소
	//printf("%u\n", &array + 1);

	return 0;
}
#endif

/***********************************************************/
// [15-5] 배열 포인터로 5x5 출력
/***********************************************************/

#if 0
#include <stdio.h>

void print_array(int** ppa);

int main(void)
{
	int array[5][5];
	int count = 1;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			array[i][j] = count++;
		}
			
	}
	print_array(array);


	return 0;
}

void print_array(int** ppa) // **ppa 대신 (*pa)[5]도 가능
{
	int(*pa)[5] = ppa;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%3d", pa[i][j]);
		}
		printf("\n");
	}
}
#endif

/***********************************************************/
// [15-7] 함수 포인터를 사용한 함수 호출
/***********************************************************/

#if 0
#include <stdio.h>

int sum(int a, int b);

int main(void)
{
	int result;
	result = sum(10, 20);
	printf("%d\n", result); // 30

	int(* fp)(int, int); // 우선순위 주의
	fp = sum;
	int result2 = fp(20, 30);
	
	printf("%d\n", result2);

	int result3 = (*sum)(30, 40);
	printf("%d\n", result3);

	return 0;
}

int sum(int a, int b)
{
	return a + b;
}
#endif

/***********************************************************/
// [15-8] 깔끔한 계산 프로그램 만들기
/***********************************************************/

#if 0
#include <stdio.h>

int sum(int a, int b);
int mul(int a, int b);
int max(int a, int b);
int sub(int a, int b);

void func(int (*fp)(int a, int b));

int main(void)
{
	printf("1 두 정수의 합\n");
	printf("2 두 정수의 곱\n");
	printf("3 두 정수중에서 큰 값 계산\n");
	printf("4 두 정수의 차\n");
	printf("원하는 연산을 선택하세요 : ");

	int menu;
	scanf("%d", &menu);

	switch (menu)
	{
	case 1: func(sum);
		break;
	case 2: func(mul);
		break;
	case 3: func(max);
		break;
	case 4: func(sub);
		break;
	default: return -1;
	}
	return 0;
}

int sum(int a, int b)
{
	return a + b;
}
int mul(int a, int b)
{
	return a * b;
}
int max(int a, int b)
{
	return a > b ? a : b;
}
int sub(int a, int b)
{
	return a > b ? a - b : b - a;
}

void func(int (*fp)(int a, int b))
{
	// sum을 넘기면 fp를 sum처럼 쓸 수 있다.
	printf("두 정수의 값을 입력하세요 : ");
	int a, b;
	scanf("%d %d", &a, &b);

	int result;
	result = fp(a, b);

	printf("결과값은 : %d\n", result);
}
#endif

/***********************************************************/
// [15-9] void 포인터 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a = 10;
	double b = 3.14;

	void* vp;
	vp = &a; // void포인터는 형변환 무조건 해줘야
	printf("%d\n", *((int*)vp));

	vp = &b;
	printf("%.2lf\n", * ((double*)vp));

	return 0;
}
#endif

/***********************************************************/
// [16-1] 동적 할당을 활용한 배열 생성
/***********************************************************/

#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N;
	printf("배열의 크기를 입력하세요 : ");
	scanf("%d", &N); //5

	// 5칸짜리 int형 배열 -> 20byte
	// int array[5]; // 20byte할당
	// malloc : 동적 할당
	// N * sizeof(int) // N개 x 4byte 만큼 할당
	// (int*)-> void pointer 를 casting해서 사용하자

	//void* vp = malloc(N * sizeof(int));
	//int* array = ((int*)vp);
	int* array = (int*)malloc(N * sizeof(int));

	//만약, 할당할 여유 공간(메모리)이 없다면 (임베디드 시스템에서 필수)
	if (array == NULL)
	{
		printf("메모리가 부족합니다ㅠㅠ\n");
		exit(1); // 프로그램 종료 stdlib.h 함수

	}

	// N : 5
	/*
	int count = 1;

	for (int i = 0; i < N; i++)
	{
		arry[i] = count++;
		printf("%3d", array[i]);
	}
	*/  //권장하진 않음 다른 로직 구현할 때 안됨

	for (int i = 0; i < N; i++) array[i] = count++;
	for (int i = 0; i < N; i++) printf("%3d", array[i]);

	//동적 할당 해제 
	//해제 안해주면 그대로 남음 점점 쓸 공간 부족해짐
	free(array);
	// 단, 해제한 이후 더이상 array를 출력할 수 없다.
	// 쓰레기값 출력됨, 잘못되면 강제종료 될수도


	return 0;

}
#endif

/***********************************************************/
// [16-2] 연속 할당과 재할당
/***********************************************************/

#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N;
	printf("배열의 크기를 입력하세요 : ");
	scanf("%d", &N); //5

	// calloc -> 초기화 : 0

	int* array = (int*)calloc(N, sizeof(int));

	if (array == NULL)
	{
		printf("메모리 부족");
		exit(1);
	}

	int count = 1;
	for (int i = 0; i < N; i++)
	{

		array[i] = count++;
	}
	for (int i = 0; i < N; i++)
	{
		printf("%3d", array[i]);
	}

	printf("\n");

	// N : 20 -> N : 30
	int M;
	printf("재조정할 배열의 크기 입력 : ");
	scanf("%d", &M);
	array = (int*)realloc(array, M * sizeof(int));


	for (int i = N; i < M; i++)
	{
		array[i] = count++;
	}

	for (int i = 0; i < M; i++)
	{
		printf("%3d", array[i]);
	}

	free(array); // 메모리 누수 방지를 위한 점유 해제

	return 0;
}
#endif

/***********************************************************/
// [16-4] 3개의 문자열을 저장하기 위한 동적 할당
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	// 3개의 문자열 -> input
	// 각 문자열의 길이 모른다
	char* str[3]; // 각 문자열을 담을 3개 공간
	char temp[46] = { '\0', };
	for (int i = 0; i < 3; i++)
	{
		gets(temp); // temp : rabbit 
		str[i] = (char*)malloc(strlen(temp) + 1);
		strcpy(str[i], temp);
		if (str[i] == NULL)
		{
			printf("메모리 부족");
			exit(1);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%s ", str[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		free(str[i]);
	}
	return 0;
}
#endif

/***********************************************************/
// [16-5] 몇 개??? 를 받아 문자열 출력
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h> // 문자열 
#include <stdlib.h> // 동적 할당

int main(void)
{
	// 사용자가 문자열을 입력
	// 몇 개 입력할 지 모름
	// 최대 20개 까지만입력받도록 설계
	char* str[21];
	char temp[46];
	
	for (int i = 0; i < 20; i++)
	{
		printf("문자열을 입력하세요 : ");
		gets(temp);
		if (strcmp(temp, "end") == 0)
		{
			break;
		}
		str[i] = (int*)malloc(strlen(temp) + 1);

		if (str[i] == NULL)
		{
			printf("메모리 부족");
			exit(1);
		}

		strcpy(str[i], temp);
	}
	
	for (int i = 0; i < 20; i++)
	{
		if (str[i] != NULL)
		{
			printf("%s\n", str[i]);
		}
		printf("%s\n", str[i]);
	}

	for (int i = 0; str[i] != NULL; i++)
	{
		free(str[i]);
	}
	return 0;
}

#endif

/***********************************************************/
// [16-5] 몇 개??? 를 받아 문자열 출력 함수구현
/***********************************************************/

#if 0
#include <stdio.h>
#include <stdlib.h> // 동적할당
#include <string.h> // strcpy, strlen

void print_array(char** ppa); // 크기 던저야할까요? 안해도됨 > char이어서
int main(void)

{
	//사용자가 문자열을 입력
	// 몇개 입력할지 모름
	// 최대 20개까지만 입력하도록 설계
	char* str[21];
	char temp[46];

	// 입력받아서 str[i]에 저장하는구문
	for (int i = 0;i < 20;i++) 
	{
		printf("문자열을 입력하세요 :");
		gets(temp);
		if (strcmp(temp, "end") == 0) break;
		str[i] = (int*)malloc(strlen(temp) + 1);

		if (str[i] == NULL) exit(1);

		strcpy(str[i], temp);
	}
	//출력
	print_array(str);

	for (int i = 0;i < 20;i++) 
	{
		free(str[i]);
	}

	return 0;
}
void print_array(char** ppa)
{
	while (*ppa) printf("%s\n", *ppa++);
}

#endif

/***********************************************************/
// [16-6] 명령 프롬프트 인자를 출력하는 프로그램
/***********************************************************/

#if 0
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
	// 수정 후 Ctrl+Shift+B
	printf("Hello World!!\n");
	/*for (int i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}*/
	
	int size = atoi(argv[1]);



	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
#endif

/***********************************************************/
// [17-1] 구조체 선언 및 사용
/***********************************************************/

#if 0
#include <stdio.h>

// 구조체 선언!! (반드시 main앞에)
struct contact
{
	// 멤버
	// 자료형 멤버명;
	char* name; // 이름
	int age; // 나이
	char* mbti; // MBTI
};

struct student
{
	char ch1;
	short num;
	char ch2;
	int score;
	double grade;
	char ch3;
};

struct exam
{
	char c1;
	int num;
};

int main(void)
{
	struct contact p1;
	struct contact p2;
	struct contact p3;

	struct student s1;

	struct exam e1;
	printf("e1의 크기 : %d\n", sizeof(e1));
	printf("s1의 크기 : %d\n", sizeof(s1));
	
	// .(~의, 안에)
	p1.name = "정 태윤";
	p1.age = 24;
	p1.mbti = "ISTP";

	p2.name = "리오넬 메시";
	p2.age = 37;
	p2.mbti = "GOAT";

	p3.name = "오타니 쇼헤이";
	p3.age = 30;
	p3.mbti = "GOAT";

	// 구조체 -> 설계도

	printf("이름 : %s, 나이 : %d세, MBTI : %s\n", p1.name, p1.age, p1.mbti);
	printf("이름 : %s, 나이 : %d세, MBTI : %s\n", p2.name, p2.age, p2.mbti);
	printf("이름 : %s, 나이 : %d세, MBTI : %s\n", p3.name, p3.age, p3.mbti);
	return 0;
}
#endif

/***********************************************************/
// [17-2] 멤버의 자료형
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
	// 학번, 학점 정보 추가
	int id;
	double grade;
};

struct profile
{
	char name[20]; // 이름
	int age;       // 나이
	double height; // 키
	char* intro;   // 자기소개

	struct student st; //학생 관련 정보

};
int main(void)
{
	// 자기소개 문구를 입력 받아 intro에 대입
	struct profile p1;
	// strcpy()
	strcpy(p1.name, "선동렬");
	
	p1.age = 20;
	p1.height = 600;
	// 자기소개 문구를 입력 받아 info에 대입
	printf("자기소개 : ");
	// 임시 저장 공간
	char temp[80];
	gets(temp);

	p1.intro = (char*)malloc(strlen(temp) + 1);
	strcpy(p1.intro, temp);

	p1.st.id = 2019;
	p1.st.grade = 1.20;


	printf("이름 : %s, 나이 : %d세, 키 : %.1lfcm\n", p1.name, p1.age, p1.height);
	printf("자기소개 : %s\n", p1.intro);
	printf("학번 : %d, 학점 : %.2lf\n", p1.st.id, p1.st.grade);

	return 0;
}
#endif

/***********************************************************/
// [17-3] 최고 학점의 학생 데이터 출력
/***********************************************************/

#if 0
#include <stdio.h>

struct student
{
	int id; //학번
	char name[20]; // 이름
	double grade; // 학점
};

int main(void)
{
	// 구조체선언과 동시에 초기화
	struct student s1 = { 315, "선동렬", 1.2 },
					s2 = { 316, "김광현", 3.7 },
					s3 = { 317, "게릿콜", 3.2 };

	// s1, s2, s3의 학점을 탐색하면서
    // 가장 높은 학점을 가지고 있는 사람의
    // 다음과 같이 학번, 이름, 학점을 출력
    // 학번 : ???, 이름 : ???, 학점 : ???


	// 첫 번째 가장 높은 학점이다!!
	// 가장 높은 구조체 -> max
	// 구조체는 결국 자료형(사용자 정의된)
	// 기본 자료형 끼리는 대입 연산자 사용 가능
	// 초기화 이후에 대입 가능하다~!!
	struct student max = s1;

	if (s2.grade > max.grade)
	{
		max = s2;
	}
	if (s3.grade > max.grade)
	{
		max = s3;
	}
	printf("학번 : %d, 이름 : %s, 학점 : %.1lf\n", max.id, max.name, max.grade);

	/*double max = 0;
	int max_index = 0;
	if (s1.grade > max)
	{
		max = s1.grade;
		max_index++;
	}
	if (s2.grade > max)
	{
		max = s2.grade;
		max_index++;
	}
	if (s3.grade > max)
	{
		max = s3.grade;
		max_index++;
	}
	switch (max_index)
	{
	case 1: printf("학번 : %d, 이름 : %s, 학점 : %.1lf\n", s1.id, s1.name, s1.grade);
		break;
	case 2: printf("학번 : %d, 이름 : %s, 학점 : %.1lf\n", s2.id, s2.name, s2.grade);
		break;
	case 3: printf("학번 : %d, 이름 : %s, 학점 : %.1lf\n", s3.id, s3.name, s3.grade);
		break;
	}*/
	
	return 0;
}
#endif

/***********************************************************/
// [17-6] 구조체 포인터와 간접 멤버 접근 연산자
/***********************************************************/

#if 0
#include <stdio.h>

struct score
{
	int kor;
	int eng;
	int math;
};

int main(void)
{
	struct score s1 = { 70, 80, 90 };
	struct score* ps = &s1;

	printf("국어 : %d점\n", s1.kor);
	printf("영어 : %d점\n", (*ps).eng);
	printf("수학 : %d점\n", ps->math); // -> : 간접 멤버 접근 연산자


	return 0;
}
#endif

/***********************************************************/
// [17-7] 구조체 배열
/***********************************************************/

#if 1
#include <stdio.h>
void print_list(struct student* lp, int size);

struct student
{
	int id; //학번
	char name[20]; // 이름
	double grade; // 학점
};

int main(void)
{
	// 구조체선언과 동시에 초기화
	struct student students[3] = {
		{ 315, "선동렬", 1.2 },
		{ 316, "김광현", 3.7 },
		{ 317, "구창모", 3.6 }
	};

	print_list(students, 3);

	// 3명의 정보를 다음과 같이 3행으로 출력
    // 학번 : 315, 이름 : 홍길동, 학점 : 2.4
    // 학번 : 316, 이름 : 임꺽정, 학점 : 3.7
    // 학번 : 317, 이름 : 심청이, 학점 : 4.5

	
	return 0;
}

void print_list(struct student* lp, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("학번 : %d, 이름 : %s, 학점 : %.1lf\n", lp[i].id, (*(lp+i)).name, (lp + i)->grade);
	}
}
#endif

// 4月18日
/***********************************************************/
// [17-9] 자기 참조 구조체
/***********************************************************/
// 연결 리스트는 이걸로 다 해결 가능
#if 0
#include <stdio.h>

struct list
{
	int num;
	struct list* next;
};

int main(void)
{
	// list : Linked List(연결 리스트)
	struct list a = { 10, }, b = { 20, }, c = { 30, };
	// 처음 값인 a를 가리키기 위한 주소
	// head의 값은 절대 변경하지 않는다.
	const struct list* head = &a;

	a.next = &b;
	b.next = &c;

	printf("a : %d, a 의 next값 :  %p\n", a.num, a.next);
	printf("b : %d, b 의 next값 : %p\n", a.next->num, a.next->next);
	printf("c : %d, c 의 next값 : %p\n", a.next->next->num, a.next->next->next);

	printf("list all : ");
	struct list* current = head;

	/*printf("%d ", current->num);
	current = current->next;

	printf("%d ", current->num);
	current = current->next;

	printf("%d ", current->num);*/

	while (current!=NULL)
	{
		printf("%d ", current->num);
		current = current->next;
	}
	return 0;
}
#endif

/***********************************************************/
// [17-10] 공용체 union
/***********************************************************/

#if 0
#include <stdio.h>

union data
{
	int i;
	double d;
} weather_data;

int main(void)
{
	// 패킷을 통해 타 디바이스에서
	// data를 전송하고자 한다.
	// 2개 data가 오는데
	// 1. 정수형습도 84%
	// 2. 실수형 기온 17.1도

	// 84, 17.1, 85, 17.2, 86, 17.3 ... 이렇게 data 넘어온다.
	char *str = "84";

	int count = 1;
	if (count % 2 == 1)
	{
		weather_data.i = 84;
		count++;
	}
	else
	{
		weather_data.d = 17.1;
		count++;
	}

	weather_data.i;
	weather_data.d;

	return 0;
}
#endif

/***********************************************************/
// [17-11] 열거형
/***********************************************************/

#if 0
#include <stdio.h>

// 초기화 안해주면 0 1 2 .. 할당된 다음 값으로 초기화 왠만하면 초기화 해줄것
enum discount { NORMAL, EARLY = 4000, TELECOM = 2000 }; 

int main(void)
{
	// 영화 예매 프로그램
	int menu;
	printf("[1]없음 [2]조조 [3]통신사 할인\n");
	printf("할인 권종을 선택하세요 : ");
	scanf("%d", &menu);
	int ticket_price = 14000;

	switch (menu)
	{
	case 1: ticket_price -= NORMAL; break;
	case 2: ticket_price -= EARLY; break;
	case 3: ticket_price -= TELECOM; break;
	default: break;
	}

	printf("결제 금액 : %d", ticket_price)
		;	return 0;
}
#endif

/***********************************************************/
// [17-12] typedef 을 사용한 자료형 재정의
/***********************************************************/

#if 0
#include <stdio.h>
#include <time.h>

typedef signed int 정수;

struct student
{
	int num;
	double grade;
};
typedef struct student Student;
typedef struct
{
	char name[20];
	int age;
} Profile;

int main(void)
{
	clock_t t = clock();

	// 구조체를 재정의하면
	// 대문자로 시작하자
	Student s1 = { 315, 3.7 };

	int a = 10;
	정수 b = 20;
	printf("%d, %d", a, b);

	return 0;
}
#endif

/***********************************************************/
// [18-1] 파일 열고 닫기
/***********************************************************/

#if 0
#include <stdio.h>

#define PATH "C:\\Users\\aiot24_\\Desktop\\workspace_c\\a.txt"
int main(void)
{
	FILE* fp;
	const char* path = "C:\\Users\\aiot24_\\Desktop\\workspace_c\\a.txt";

	// 상대 경로로 경로 정할 때,
	// 우리가 지금 바라봤을 때 -> Ctrl + F5
	// 컴파일 배포 -> exe
	fp = fopen(path, "r");
	if (fp == NULL)return 1;
	printf("파일이 열렸습니다.\n");

	// file get char
	int ch;
	while (1)
	{
		ch = fgetc(fp);
		if (ch == EOF) break;
		putchar(ch);
	}
	fclose(fp); // 열었으면 닫자!! 열었으면 닫자!!
	return 0;
}
#endif

/***********************************************************/
// [18-2] b.txt 만들기
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	FILE* fp;
	const char* path = "C:\\Users\\aiot24_\\Desktop\\workspace_c\\b.txt";
	fp = fopen(path, "w");
	if (fp == NULL) return 1;

	char* words = "C CLEAR!!!!";

	/*
	while (1)
   {
      // fputc(문자, 파일 포인터);
      fputc(*words, fp);
      words++;
      if (*words == NULL) break;
   }
	*/

	while (*words != NULL) fputc(*words++, fp);
	fputc('\n', fp);

	fclose(fp); // 열었으면 닫자, 열었으면 닫자
	return 0;
}
#endif

/***********************************************************/
// [18-3] 파일 입출력
/***********************************************************/
#if 0
#include <stdio.h>
#include <string.h>
int main(void)
{
	FILE* fpa, * fpb, * fpc;
	const char* origin_path = "C:\\Users\\aiot24_\\Desktop\\workspace_c\\";
	char path_a[256] = { 0, };
	char path_b[256] = { 0, };
	char path_c[256] = { 0, };
	strcpy(path_a, origin_path);
	strcpy(path_b, origin_path);
	strcpy(path_c, origin_path);
	strcat(path_a, "a.txt");
	strcat(path_b, "b.txt");
	strcat(path_c, "c.txt");

	fpa = fopen(path_a, "r");
	if (fpa == NULL) return 1;

	fpb = fopen(path_b, "r");
	if (fpb == NULL) return 2;

	fpc = fopen(path_c, "w");
	if (fpc == NULL) return 3;

	char temp[256] = { 0, };
	// 1. a.txt 읽어서 temp에 담기!! // Hello World!!
	// 2. b.txt 읽어서 temp에 추가!! // Hello World!! C CLEAR!!
	// 3. temp를 c.txt에 그대로 쓰기
	char* pt = temp;
	int ch;
	while (1)
	{
		ch = fgetc(fpa);
		*pt++ = ch;
		if (ch == EOF) break;
	}
	pt--;

	while (1)
	{
		ch = fgetc(fpb);
		*pt++ = ch;
		if (ch == EOF) break;
	}
	pt--;
	*pt = '\0';

	pt = temp; // 쓰기 위해 포인터 맨 왼쪽으로 이동!!
	while (1)
	{
		fputc(*pt, fpc);
		pt++;
		if (*pt == NULL) break;
	}
	fputc('\n', fpc);

	printf("%s\n", temp);

	fclose(fpa);
	fclose(fpb);
	fclose(fpc);

	return 0;
}
#endif

/***********************************************************/
// [18-4,5] 표준 입출력, stdin, stdout
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int ch;
	while (1)
	{
		ch = getchar();
		if (ch == EOF) break;
		putchar(ch);
	}
	
	while (1)
	{
		ch = fgetc(stdin); // 현재 os와 연결된 키보드
		if (ch == EOF) break;
		fputc(ch, stdout);  
	}
	return 0;
}
#endif

/***********************************************************/
// [18-6] 파일 형태와 개방 모드가 다른 경우 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	FILE* fp;
	char* path = "C:\\Users\\aiot24_\\Desktop\\workspace_c\\d.txt";
	fp = fopen(path, "wb");
	if (fp == NULL) return 1;

	int array[10] = { 13, 10, 13, 13, 10, 26, 13, 10, 13, 10 };
	for (int i = 0; i < 10; i++)
	{
		fputc(array[i], fp);
	}
	fclose(fp);

	//txt 형식으로 읽어보자
	fp = fopen(path, "rt");
	int ch;
	while (1)
	{
		ch = fgetc(fp);
		if (ch == EOF) break;
		printf("%3d", ch);
	}
	fclose(fp);

	return 0;
}
#endif

/***********************************************************/
// [18-7] a+모드로 파일 내용 확인하며 출력
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h> // strcmp()
int main(void)
{
	FILE* fp;
	// 경로 끝에 music.txt
	char* path = "C:\\Users\\aiot24_\\Desktop\\workspace_c\\music.txt";
	// 추가될 데이터(문자열) 임시 저장되는 공간
	char str[20];

	fp = fopen(path, "a+");
	if (fp == NULL) return 1;

	// logic

	while (1) {
		printf("노래 제목 : "); // 아몬드 초콜릿
		scanf("%s", str);
		if (strcmp(str, "end") == 0) break; // end <- 프로그램 종료
		else if (strcmp(str, "list") == 0) // list <- 현재까지 저장된 모든 노래 출력!!
		{
			// 모든 정보 출력하기 전
			// fp를 맨 첫 줄 
			// 맨 앞으로 이동시키자
			fseek(fp, 0, SEEK_SET);
			while (1)
			{
				// 개행(\n)가져오기 위해 +1
				fgets(str, strlen(str) + 1, fp);
				// 행 끝에 도달하면
				// feof() -> 
				if (feof(fp) != 0) break;
				printf("%s", str);
			}
		}
		// while(1) fputc(), -> 문장 전체를 입력, fputs() fprintf
		else fprintf(fp, "%s\n", str);
		// str에 들어 있는 노래 정보를
		// 맨 끝에 d.txt에 쓰자!! 
	}

	fclose(fp); // 열었으면 닫자, 열었으면 닫자!!
	return 0;
}
#endif

/***********************************************************/
// [18-8] 여러 줄의 문장을 입력해 한 줄로 내보내기
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h> // strlen
int main(void)
{
	// a : Hello World!!
	// b : C CLEAR!!
	// 2개를 e에 내보내기
	char* path_a = "C:\\Users\\aiot24_\\Desktop\\workspace_c\\a.txt";
	char* path_b = "C:\\Users\\aiot24_\\Desktop\\workspace_c\\b.txt";
	char* path_e = "C:\\Users\\aiot24_\\Desktop\\workspace_c\\e.txt";

	FILE* fpa, * fpb, * fpe;
	fpa = fopen(path_a, "r");
	if (fpa == NULL) return 1;

	fpb = fopen(path_b, "r");
	if (fpb == NULL) return 2;

	fpe = fopen(path_e, "w");
	if (fpe == NULL) return 3;

	char str[80];
	char* result;

	while (1)
	{
		result = fgets(str, strlen(str) + 1, fpa);
		if (result == NULL)
		{

			/*while (1)
			{
			   result = fgets(str, strlen(str) + 1, fpb);
			   if (result == NULL) break;
			}*/
			break;
		}
		fputs(result, fpe);
	}
	fclose(fpa);
	fclose(fpb);
	fclose(fpe);

	return 0;
}
#endif

/***********************************************************/
// [18-9] fprintf() 다양한 형식으로 내보내기
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	// ive.txt
	/*
	유진 10 20 30
	원영 11 22 33
	레이 44 55 66
	*/

	FILE* fp;
	char *path = "C:\\Users\\aiot24_\\Desktop\\workspace_c\\ive.txt";
	fp = fopen(path, "r");
	if (fp == NULL) return 1;

	

	FILE* fs;
	char* path_score = "C:\\Users\\aiot24_\\Desktop\\workspace_c\\score.txt";
	fs = fopen(path_score, "w");
	if (fs == NULL) return 2;

	// 이름 국 영 수
	char name[20];
	int kor, eng, math;
	int total;
	double avg;

	int result;
	while (1)
	{
		result = fscanf(fp,"%s %d %d %d", name, &kor, &eng, &math);
		if (result == EOF) break;
		total = kor + eng + math;
		avg = total / 3.0;

		fprintf(fs, "%3s %4d %.1lf\n", name, total, avg);
	}

	fclose(fp);
	fclose(fs);
	
	return 0;
}
#endif
