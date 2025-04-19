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