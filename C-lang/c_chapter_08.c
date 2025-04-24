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
