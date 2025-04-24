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