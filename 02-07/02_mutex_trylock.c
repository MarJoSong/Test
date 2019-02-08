#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


void* thr(void* arg)
{
	while(1)
	{
		printf("开始对子线程加锁\n");
		pthread_mutex_lock(&mutex);
		printf("HELLOWORLD\n");
		sleep(10);
		pthread_mutex_unlock(&mutex);
		printf("子线程解锁\n");
	}
}

int main(int argc, char* argv[])
{
	pthread_t tid;
	pthread_create(&tid, NULL, thr, NULL);
	sleep(1);
	while(1)
	{
		int ret = pthread_mutex_trylock(&mutex);
		if(ret>0)
		{
			printf("尝试对主线程加锁失败\n");
			printf("返回值: %d, 错误信息: %s\n", ret, strerror(ret));
		}
		else
		{
			printf("尝试对主线程加锁成功\n");
			printf("main lock success\n");
		}
		sleep(1);
	}

	pthread_mutex_destroy(&mutex);
	return 0;
}

