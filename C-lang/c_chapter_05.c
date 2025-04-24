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