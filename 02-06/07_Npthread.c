#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void* thr(void* arg)
{
	int num = (int)arg;
	printf("I am %d thread, self = %lu\n", num, pthread_self());
	return (void*)(100+num);//等同于pthread_exit((void*)100)
}

int main(int argc, char* argv[])
{
	pthread_t tid[5];
	int i;
	for(i=0;i<5;++i)
	{
		pthread_create(&tid[i], NULL, thr, (void*)i);
	}

	void* ret;
	for(i=0;i<5;++i)
	{
		pthread_join(tid[i], &ret);
		printf("i = %d, ret = %d\n", i, (int)ret);
	}
	pthread_exit(NULL);//等同于return NULL
}

