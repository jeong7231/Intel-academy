#include <stdio.h>      // 입출력 함수 사용을 위한 헤더
#include <stdlib.h>     // 표준 라이브러리 함수 (exit 등) 사용을 위한 헤더
#include <string.h>     // 문자열 처리 함수 사용을 위한 헤더
#include <unistd.h>     // POSIX 시스템 호출 (read, write, close 등) 사용을 위한 헤더
#include <arpa/inet.h>  // 인터넷 주소 체계 함수 (inet_addr 등) 사용을 위한 헤더
#include <sys/socket.h> // 소켓 프로그래밍을 위한 헤더

void error_handling(char *message); // 에러 처리 함수 선언

int main(int argc, char *argv[])
{
    int sock; // 클라이언트 소켓 파일 디스크립터
    struct sockaddr_in serv_addr; // 서버 주소 정보 구조체
    char message[1024]; // 전송할 메시지를 저장할 배열
    int str_len; // 수신한 데이터 길이를 저장할 변수

    // 입력 인자 확인 (IP주소, 포트번호 필수)
    if(argc != 3)
    {
        printf("Usage : %s <IP> <port>\n", argv[0]);
        exit(1); // 인자 개수가 잘못되었으면 프로그램 종료
    }

    sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); // TCP 소켓 생성
    if (sock < 0)
        error_handling("socket() error"); // 소켓 생성 실패시 에러 처리

    memset(&serv_addr, 0, sizeof(serv_addr)); // serv_addr 구조체 초기화
    serv_addr.sin_family = AF_INET; // IPv4 사용
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]); // 문자열 IP 주소를 네트워크 바이트 순서로 변환
    serv_addr.sin_port = htons(atoi(argv[2])); // 문자열 포트를 정수로 변환 후 네트워크 바이트 순서로 저장

    if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("connect() error!"); // 서버 연결 실패시 에러 처리

    do {
        //printf("입력하세요. 종료는 quit : "); // 사용자에게 입력 요청 printf 어지간하면 사용x
        
        fputs("입력하세요. 종료는 quit : ", stdout); // 사용자에게 입력 요청
        fgets(message, sizeof(message), stdin); // 사용자로부터 입력 받음
        
        message[strcspn(message, "\n")] = 0; // fgets로 입력시 끝에 붙는 개행문자 제거
				
				/*
				개행문자 제거 (교수님 설명)
				message[strlen(message0 - 1] = '\0' ;  0넣어도됨
				*/
				
        if(strcmp(message, "quit") == 0)
            break; // 입력이 "quit"이면 반복문 탈출
        /*
        quit (교수님 설명)
				if(!strcmp(message, "quit")) break;   
				*/   
				
				/*
				length = strlen(message)  
				함수를 한번이라도 덜 호출할 수 있도록 함수로만들자
				실행시간도 빨라짐
				널문자제거 시점 고려해야함
				*/

        write(sock, message, strlen(message)); // 서버로 메시지 전송, 널문자 안들어감
        
        str_len = read(sock, message, sizeof(message) - 1); 
        // 서버로부터 응답 수신 
        // NULL문자 채우기 위해 -1 로 공간 만들어주기
        
        if(str_len < 0)
            error_handling("read() error!"); // 읽기 실패시 에러 처리
        
        else if(str_len == 0) // 서버 소켓 종료 시 0리턴 서버종료하면 클라이언트도 종료시키기
		        break;
		        
			  else 
			  {
		        message[str_len] = '\0'; // 문자열 끝에 NULL 문자 추가 (문자열 안전 처리)
		        printf("Message from server: %s\n", message); // 서버로부터 받은 메시지 출력
		    }
		     
		     /* 제일 빈번하게 실행될 코드를 제일 위쪽으로 그래야 한번이라도 if문 덜 실행해서 속도향상 가능
		     if(str_len > 0)
		     {
		        message[str_len] = '\0'; // 문자열 끝에 NULL 문자 추가 (문자열 안전 처리)
		        printf("Message from server: %s\n", message); // 서버로부터 받은 메시지 출력
		     }
		     else if(str_len == 0) // 서버 소켓 종료 시 0리턴 서버종료하면 클라이언트도 종료시키기
		        break;
		     else 
            error_handling("read() error!"); // 읽기 실패시 에러 처리
		     */

    } while(1); // 사용자가 "quit" 입력할 때까지 반복

    close(sock); // 소켓 종료
    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr); // 에러 메시지를 표준 에러로 출력
    fputc('\n', stderr);    // 줄바꿈 문자 출력
    exit(1);                // 비정상 종료
}

