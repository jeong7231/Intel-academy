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

#if 0
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