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