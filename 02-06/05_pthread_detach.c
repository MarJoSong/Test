#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void* thr(void* arg)
{
	printf("I am a thread, slef = %lu\n", pthread_self());
	sleep(2);
	printf("I am a thread, slef = %lu\n", pthread_self());
	return NULL;
}

int main(int argc, char* argv[])
{
	pthread_t tid;
	pthread_create(&tid, NULL, thr, NULL);
	pthread_detach(tid);//线程分离
	sleep(5);

	int ret;
	if((ret=pthread_join(tid, NULL))>0)
	{
		printf("join err:%d, %s\n", ret, strerror(ret));
	}
	return 0;
}

