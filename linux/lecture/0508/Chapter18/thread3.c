#include <stdio.h>
#include <pthread.h>
void * thread_summation(void * arg); 

int sum=0;

int main(int argc, char *argv[])
{
	pthread_t id_t1, id_t2;
	int range1[]={1, 5};
	int range2[]={6, 10};
	
	// 같은 스레드 함수를 여러 스레드로 호출
	// 동일한 함수를 스레드로 계속 추가하는 형태
	pthread_create(&id_t1, NULL, thread_summation, (void *)range1);
	pthread_create(&id_t2, NULL, thread_summation, (void *)range2);

	pthread_join(id_t1, NULL);
	pthread_join(id_t2, NULL);
	printf("result: %d \n", sum);
	return 0;
}
// 얘실행됬다 쟤실행됬다 해도 전체 합이라는 값은 똑같이 유지될것?

void * thread_summation(void * arg) 
// void *thread_summation(void arg[]) // 보이드라 크기정보 알 수 없어서 안됨
{
	int start=((int*)arg)[0];
	int end=((int*)arg)[1];

	while(start<=end)
	{
		sum+=start;
		start++;
	}
	return NULL;
}
