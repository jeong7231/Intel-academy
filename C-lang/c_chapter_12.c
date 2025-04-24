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