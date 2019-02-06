#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

int var = 100;

void* thr(void* arg)
{
	printf("I am a thread, var = %d\n", var);
	sleep(1);
	var = 1001;
	sleep(2);
	printf("I am a thread, var = %d\n", var);
	return NULL;
}

int main(int argc, char* argv[])
{
	pthread_t tid;
	pthread_create(&tid, NULL, thr, NULL);
	pthread_detach(tid);//线程分离
	printf("I am a thread, var = %d\n", var);
	sleep(2);
	printf("I am a thread, var = %d\n", var);
	var = 1003;
	printf("I am a thread, var = %d\n", var);
	int ret;
	if((ret=pthread_join(tid, NULL))>0)
	{
		printf("join err:%d, %s\n", ret, strerror(ret));
	}
	return 0;
}

