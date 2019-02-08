#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;

int beginNum = 0;

void* thr_read(void* arg)
{
	while(1)
	{
		pthread_rwlock_rdlock(&rwlock);
		printf("加读锁 Num = %d self = %lu\n", beginNum, pthread_self());
		usleep(2000);
		pthread_rwlock_unlock(&rwlock);
		usleep(5000);
	}
}

void* thr_write(void* arg)
{
	while(1)
	{
		pthread_rwlock_wrlock(&rwlock);
		printf("加写锁 Num = %d self = %lu\n", ++beginNum, pthread_self());
		usleep(2000);
		pthread_rwlock_unlock(&rwlock);
		usleep(3000);
	}
}

int main(int argc, char* argv[])
{
	int i;
	pthread_t tid[8];
	for(i=0; i<5; ++i)
	{
		pthread_create(&tid[i], NULL, thr_read, NULL);
	}
	for(; i<8; ++i)
	{
		pthread_create(&tid[i], NULL, thr_write, NULL);
	}

	for(i=0;i<8;++i)
	{
		pthread_join(tid[0], NULL);
	}
	pthread_rwlock_destroy(&rwlock);
	return 0;
}

