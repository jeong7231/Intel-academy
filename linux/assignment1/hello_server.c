#include <stdio.h>      // 입출력 함수 사용을 위한 헤더
#include <stdlib.h>     // 표준 라이브러리 함수 (exit 등) 사용을 위한 헤더
#include <string.h>     // 문자열 처리 함수 사용을 위한 헤더
#include <unistd.h>     // POSIX 시스템 호출 (read, write, close 등) 사용을 위한 헤더
#include <arpa/inet.h>  // 인터넷 주소 체계 함수 사용을 위한 헤더
#include <sys/socket.h> // 소켓 프로그래밍을 위한 헤더

void error_handling(char *message); // 에러 처리 함수 선언

int main (int argc, char *argv[])
{
    int serv_sock; // 서버 소켓 파일 디스크립터
    int clnt_sock; // 클라이언트 소켓 파일 디스크립터
    struct sockaddr_in serv_addr; // 서버 주소 정보 구조체
    struct sockaddr_in clnt_addr; // 클라이언트 주소 정보 구조체
    socklen_t clnt_addr_size; // 클라이언트 주소 크기
    char message[1024]; // 수신/송신할 메시지 저장할 배열
    int str_len; // 수신한 데이터 길이 저장할 변수

    // 포트 번호 입력 확인
    if(argc != 2)
    {
        printf("Usage : %s <port>\n", argv[0]);
        exit(1); // 인자 개수가 맞지 않으면 종료
    }

    serv_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); // TCP 소켓 생성
    if(serv_sock == -1)
        error_handling("socket() error"); // 소켓 생성 실패시 에러 처리

    memset(&serv_addr, 0, sizeof(serv_addr)); // 서버 주소 구조체 초기화
    serv_addr.sin_family = AF_INET; // IPv4 사용
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // 서버의 IP 주소를 자동 할당 (0.0.0.0)
    serv_addr.sin_port = htons(atoi(argv[1])); // 문자열 포트를 정수 변환 후 네트워크 바이트 순서로 저장

    if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1)
        error_handling("bind() error"); // 바인드 실패시 에러 처리

    if(listen(serv_sock, 5) == -1)
        error_handling("listen() error"); // 리슨 실패시 에러 처리 (대기 큐 5개)

    clnt_addr_size = sizeof(clnt_addr); // 클라이언트 주소 구조체 크기 저장

    do {
        clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size); // 클라이언트 접속 대기 및 수락 -> clnt_sock로 담음

        if (clnt_sock < 0) // 수락 실패시
        {
            fputs("accept() error\n", stderr); // 에러 메시지 출력
        }

        do {
            str_len = read(clnt_sock, message, sizeof(message)); // 클라이언트로부터 데이터 수신 -> str_len 으로 넘김 -> quit 시 0리턴
            
            /*
	          if (str_len == 0) break;  while(1)로 무한루프 돌릴 때
            */

            message[str_len] = '\0'; // 문자열 끝에 NULL 문자 추가

            fputs(message, stdout); // 받은 메시지 출력
            fputc('\n', stdout); // 줄바꿈 출력
            write(clnt_sock, message, str_len); // 받은 메시지를 그대로 다시 클라이언트에게 전송 크기는 받은 메시지 만큼만
            printf("clnt_sock : %d clinent disconnected\n", clnt_sock); //이것도 fputs로?
            /*
            클로즈를 안쪽에 넣어줘야한다?
            close(clnt_sock);
            */
            
            /*
	          if (str_len == 0) break;  while(1)로 무한루프 돌릴 때
            
            message[str_len] = '\0'; // 문자열 끝에 NULL 문자 추가

            fputs(message, stdout); // 받은 메시지 출력
            fputc('\n', stdout); // 줄바꿈 출력
            write(clnt_sock, message, str_len); // 받은 메시지를 그대로 다시 클라이언트에게 전송 크기는 받은 메시지 만큼만
            printf("clnt_sock : %d clinent disconnected\n", clnt_sock); //이것도 fputs로?
            
            else if (str_len == 0) break;
            
            else 
            error_handling(0)
            */

        } while(str_len != 0); // 클라이언트가 데이터를 보내는 동안 반복 (연결 유지)

    } while(1); // 서버는 계속해서 새로운 연결을 기다림

    sleep(1); // 잠깐 대기 (안정적인 종료를 위해)
    close(clnt_sock); // 클라이언트 소켓 닫기 (안쪽에서 닫아줘야하나?)
    close(serv_sock); // 서버 소켓 닫기
    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr); // 에러 메시지를 표준 에러로 출력
    fputc('\n', stderr);    // 줄바꿈 출력
    exit(1);                // 비정상 종료
}

