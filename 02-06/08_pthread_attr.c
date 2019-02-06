#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void* thr(void* arg)
{
	printf("I am a thread\n");
	return NULL;
}

int main(int argc, char* argv[])
{
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);//提前设置分离态可以避免会回收阻塞
	
	pthread_t tid;
	pthread_create(&tid, &attr, thr, NULL);

	int ret;
	if((ret=pthread_join(tid, NULL))>0)
	{
		printf("join err:%d, %s\n", ret, strerror(ret));
	}
	pthread_attr_destroy(&attr);

	return 0;
}

