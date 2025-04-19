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