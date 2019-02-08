#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


void* thr_hl1(void* arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		printf("HELLO");
		sleep(rand()%3);
		printf("WORLD\n");
		pthread_mutex_unlock(&mutex);
		sleep(rand()%3);
	}
}

void* thr_hl2(void* arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		printf("hello");
		sleep(rand()%3);
		printf("world\n");
		pthread_mutex_unlock(&mutex);
		sleep(rand()%3);
	}
}

int main(int argc, char* argv[])
{
	pthread_t tid[2];
	pthread_create(&tid[0], NULL, thr_hl1, NULL);
	pthread_create(&tid[1], NULL, thr_hl2, NULL);

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);

	pthread_mutex_destroy(&mutex);
	return 0;
}

