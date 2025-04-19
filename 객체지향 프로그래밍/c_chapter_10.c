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