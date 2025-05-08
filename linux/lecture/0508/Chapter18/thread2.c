#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

void* thread_main(void *arg);

//구조체는 사용자정의 자료형
// struct thread_info {
// 	// parm, *msg 넘겨줘야됨
// 	int thread_param;
// 	char *msg;

// };

// typedef struct thread_info T_INFO

typedef struct {
	// parm, *msg 넘겨줘야됨
	int thread_param;
	char *msg;

}thread_info;


int main(int argc, char *argv[]) 
{
	pthread_t t_id;
	// int thread_param=5;
	// 구조체 변수 선언
	// struct thread_info t_info; // 8바이트 잡힌다.
	thread_info t_info; // 8바이트 잡힌다.
	void * thr_ret;

	// 구조체 초기화
	t_info.thread_param = 5;
	
	// char * msg=(char *)malloc(sizeof(char)*50);
	t_info.msg = (char *)malloc(sizeof(char)*50);
	

	
	strcpy(t_info.msg, "Hello, I'am thread~ \n");

	if(pthread_create(&t_id, NULL, thread_main, (void*)&t_info.thread_param)!=0)
	{
		puts("pthread_create() error");
		return -1;
	}; 	

	if(pthread_join(t_id, &thr_ret)!=0)
	{
		puts("pthread_join() error");
		return -1;
	};

	printf("Thread return message: %s \n", (char*)thr_ret);
	//free(thr_ret);
	free(t_info.msg);
	return 0;
}

void* thread_main(void *arg) 
{
	int i;
	// int cnt=*((int*)arg);

	// struct thread_info *t_info = (struct thread_info*)arg;
	thread_info *t_info = (thread_info*)arg;
	int cnt = t_info->thread_param;

	printf("malloc : %s", t_info -> msg);

	strcpy(t_info-> msg, "test Thread msg\n");

	for(i=0; i<cnt; i++)
	{
		sleep(1);  
		puts("running thread");	 
	}
	// return (void*)msg;
	return (void*)t_info -> msg;
}


// t_thread 를 cnt에 넣어서 printf로 malloc 출력하도록