/* 서울기술교육센터 AIoT */
/* author : KSH (동적 메모리, 저수준 입출력, idpasswd.txt 파일 사용) */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/time.h>
#include <time.h>
#include <errno.h>

#define BUF_SIZE 100
#define MAX_CLNT 32
#define ID_SIZE 10
#define ARR_CNT 5

#define DEBUG
typedef struct {
    char fd;
    char *from;
    char *to;
    char *msg;
    int len;
} MSG_INFO;

typedef struct {
    int index;
    int fd;
    char ip[20];
    char id[ID_SIZE];
    char pw[ID_SIZE];
} CLIENT_INFO;

void * clnt_connection(void * arg);
void send_msg(MSG_INFO * msg_info, CLIENT_INFO * first_client_info);
void error_handling(char * msg);
void log_file(char * msgstr);
void load_file(const char* filename, CLIENT_INFO* client_info, int max_clients);

int clnt_cnt=0;
pthread_mutex_t mutx;



int main(int argc, char *argv[])
{
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_adr, clnt_adr;
    int clnt_adr_sz;
    int sock_option  = 1;
    pthread_t t_id[MAX_CLNT] = {0};
    int str_len = 0;
    int i;
    char idpasswd[(ID_SIZE*2)+3];
    char *pToken;
    char *pArray[ARR_CNT]={0};
    char msg[BUF_SIZE];

    // 동적 메모리로 파일에서 읽어오기
    CLIENT_INFO client_info[MAX_CLNT];
    load_file("idpasswd.txt", client_info, MAX_CLNT);

    if(argc != 2) {
        printf("Usage : %s <port>\n",argv[0]);
        exit(1);
    }
    fputs("IoT Server Start!!\n",stdout);

    if(pthread_mutex_init(&mutx, NULL))
        error_handling("mutex init error");

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family=AF_INET;
    serv_adr.sin_addr.s_addr=htonl(INADDR_ANY);
    serv_adr.sin_port=htons(atoi(argv[1]));

    setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, (void*)&sock_option, sizeof(sock_option));
    if(bind(serv_sock, (struct sockaddr *)&serv_adr, sizeof(serv_adr))==-1)
        error_handling("bind() error");

    if(listen(serv_sock, 5) == -1)
        error_handling("listen() error");

    while(1) {
        clnt_adr_sz = sizeof(clnt_adr);
        clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_adr, &clnt_adr_sz);
        if(clnt_cnt >= MAX_CLNT)
        {
            printf("socket full\n");
            shutdown(clnt_sock,SHUT_WR);
            continue;
        }
        else if(clnt_sock < 0)
        {
            perror("accept()");
            continue;
        }

        str_len = read(clnt_sock, idpasswd, sizeof(idpasswd));
        idpasswd[str_len] = '\0';

        if(str_len > 0)
        {
            i=0;
            pToken = strtok(idpasswd,"[:]");

            while(pToken != NULL)
            {
                pArray[i] =  pToken;
                if(i++ >= ARR_CNT)
                    break;    
                pToken = strtok(NULL,"[:]");
            }
            for(i=0;i<MAX_CLNT;i++)
            {
                if(!strcmp(client_info[i].id,pArray[0]))
                {
                    if(client_info[i].fd != -1)
                    {
                        sprintf(msg,"[%s] Already logged!\n",pArray[0]);
                        write(clnt_sock, msg,strlen(msg));
                        log_file(msg);
                        shutdown(clnt_sock,SHUT_WR);
#if 1   //for MCU
                        client_info[i].fd = -1;
#endif  
                        break;
                    }
                    if(!strcmp(client_info[i].pw,pArray[1])) 
                    {
                        strcpy(client_info[i].ip,inet_ntoa(clnt_adr.sin_addr));
                        pthread_mutex_lock(&mutx);
                        client_info[i].index = i; 
                        client_info[i].fd = clnt_sock; 
                        clnt_cnt++;
                        pthread_mutex_unlock(&mutx);
                        sprintf(msg,"[%s] New connected! (ip:%s,fd:%d,sockcnt:%d)\n",pArray[0],inet_ntoa(clnt_adr.sin_addr),clnt_sock,clnt_cnt);
                        log_file(msg);
                        write(clnt_sock, msg,strlen(msg));

                        pthread_create(t_id+i, NULL, clnt_connection, (void *)(client_info + i));
                        pthread_detach(t_id[i]);
                        break;
                    }
                }
            }
            if(i == MAX_CLNT)
            {
                sprintf(msg,"[%s] Authentication Error!\n",pArray[0]);
                write(clnt_sock, msg,strlen(msg));
                log_file(msg);
                shutdown(clnt_sock,SHUT_WR);
            }
        }
        else 
            shutdown(clnt_sock,SHUT_WR);
    }
    return 0;
}

void * clnt_connection(void *arg)
{
    CLIENT_INFO * client_info = (CLIENT_INFO *)arg;
    int str_len = 0;
    int index = client_info->index;
    char msg[BUF_SIZE];
    char to_msg[MAX_CLNT*ID_SIZE+1];
    int i=0;
    char *pToken;
    char *pArray[ARR_CNT]={0};
    char strBuff[BUF_SIZE*2]={0};

    MSG_INFO msg_info;
    CLIENT_INFO  * first_client_info;

    first_client_info = (CLIENT_INFO *)((void *)client_info - (void *)( sizeof(CLIENT_INFO) * index ));
    while(1)
    {
        memset(msg,0x0,sizeof(msg));
        str_len = read(client_info->fd, msg, sizeof(msg)-1); 
        if(str_len <= 0)
            break;

        msg[str_len] = '\0';
        pToken = strtok(msg,"[:]");
        i = 0; 
        while(pToken != NULL)
        {
            pArray[i] =  pToken;
            if(i++ >= ARR_CNT)
                break;    
            pToken = strtok(NULL,"[:]");
        }

        msg_info.fd = client_info->fd;
        msg_info.from = client_info->id;
        msg_info.to = pArray[0];
        sprintf(to_msg,"[%s]%s",msg_info.from,pArray[1]);
        msg_info.msg = to_msg;
        msg_info.len = strlen(to_msg);

        sprintf(strBuff,"msg : [%s->%s] %s",msg_info.from,msg_info.to,pArray[1]);
        log_file(strBuff);
        send_msg(&msg_info, first_client_info);
    }

    close(client_info->fd);

    sprintf(strBuff,"Disconnect ID:%s (ip:%s,fd:%d,sockcnt:%d)\n",client_info->id,client_info->ip,client_info->fd,clnt_cnt-1);
    log_file(strBuff);

    pthread_mutex_lock(&mutx);
    clnt_cnt--;
    client_info->fd = -1;
    pthread_mutex_unlock(&mutx);

    return 0;
}

void send_msg(MSG_INFO * msg_info, CLIENT_INFO * first_client_info)
{
    int i=0;

    if(!strcmp(msg_info->to,"ALLMSG"))
    {
        for(i=0;i<MAX_CLNT;i++)
            if((first_client_info+i)->fd != -1)    
                write((first_client_info+i)->fd, msg_info->msg, msg_info->len);
    }
    else if(!strcmp(msg_info->to,"IDLIST"))
    {
        char* idlist = (char *)malloc(ID_SIZE * MAX_CLNT);
        msg_info->msg[strlen(msg_info->msg) - 1] = '\0';
        strcpy(idlist,msg_info->msg);

        for(i=0;i<MAX_CLNT;i++)
        {
            if((first_client_info+i)->fd != -1)    
            {
                strcat(idlist,(first_client_info+i)->id);
                strcat(idlist," ");
            }
        }
        strcat(idlist,"\n");
        write(msg_info->fd, idlist, strlen(idlist));
        free(idlist);
    }
    else
        for(i=0;i<MAX_CLNT;i++)
            if((first_client_info+i)->fd != -1)    
                if(!strcmp(msg_info->to,(first_client_info+i)->id))
                    write((first_client_info+i)->fd, msg_info->msg, msg_info->len);
}

void error_handling(char *msg)
{
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}

void log_file(char * msgstr)
{
    fputs(msgstr,stdout);
}

/* idpasswd.txt 파일을 동적 메모리로 읽어서 CLIENT_INFO 배열에 저장 */
void load_file(const char* filename, CLIENT_INFO* client_info, int max_clients) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        error_handling("idpasswd.txt 파일 열기 실패");
    }

    // 파일 크기 구하기
    int filesize = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    // 파일 크기만큼 동적 메모리 할당
    char* buffer = (char*)malloc(filesize + 1);
    if (buffer == NULL) {
        close(fd);
        error_handling("메모리 할당 실패");
    }

    // 파일 읽기
    if (read(fd, buffer, filesize) != filesize) {
        free(buffer);
        close(fd);
        error_handling("파일 읽기 실패");
    }
    buffer[filesize] = '\0';
    close(fd);

    // CLIENT_INFO 배열 초기화
    for (int i = 0; i < max_clients; i++) {
        client_info[i].index = 0;
        client_info[i].fd = -1;
        strcpy(client_info[i].ip, "");
        strcpy(client_info[i].id, "");
        strcpy(client_info[i].pw, "");
    }

    // 각 줄 파싱하여 ID, PW 저장
    char* line = strtok(buffer, "\n");
    int idx = 0;
    while (line != NULL && idx < max_clients) {
        char id[ID_SIZE] = {0};
        char pw[ID_SIZE] = {0};
        sscanf(line, "%s %s", id, pw);
        strcpy(client_info[idx].id, id);
        strcpy(client_info[idx].pw, pw);
        idx++;
        line = strtok(NULL, "\n");
    }

    free(buffer);
}
