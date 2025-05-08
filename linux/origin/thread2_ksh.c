#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

void* thread_main(void *arg);
/*
struct thredInfo {
	int thread_param;
	char * msg;
};
typedef struct thredInfo T_Info
*/
typedef struct {
	int thread_param;
	char * msg;
}threadInfo;

int main(int argc, char *argv[]) 
{
	pthread_t t_id;
	threadInfo tInfo;
	void * thr_ret;

	tInfo.thread_param = 5;
	tInfo.msg = (char *)malloc(sizeof(char)*50);
	strcpy(tInfo.msg, "Hello, I'am thread~ \n");
	if(pthread_create(&t_id, NULL, thread_main, (void*)&tInfo)!=0)
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
//	free(thr_ret);
	free(tInfo.msg);
	return 0;
}

void* thread_main(void *arg) 
{
	int i;
///	int cnt=*((int*)arg);
/*
	threadInfo tInfo = *((threadInfo*)arg);
	int cnt = tInfo.thread_param;
	printf("malloc : %s  \n",tInfo.msg);
	strcpy(tInfo.msg, "test Thread msg\n");
*/
	threadInfo* tInfo = (threadInfo*)arg;
//	int cnt = (*tInfo).thread_param;
	int cnt = tInfo->thread_param;

//	printf("malloc : %s  \n",(*tInfo).msg);
	printf("malloc : %s  \n",tInfo->msg);
//	strcpy((*tInfo).msg, "test Thread msg\n");
	strcpy(tInfo->msg, "test Thread msg\n");
	for(i=0; i<cnt; i++)
	{
		sleep(1);  puts("running thread");	 
	}
//	return (void*)(*tInfo).msg;
	return (void*)tInfo->msg;
}
