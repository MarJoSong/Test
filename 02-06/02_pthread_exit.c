#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void* thr(void* arg)
{
	printf("I am a new thread, pid = %d, tid = %d\n", getpid(), pthread_self());
	//return NULL;
	pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
	pthread_t tid;
	pthread_create(&tid, NULL, thr, NULL);
	printf("I am main thread, pid = %d, tid = %d\n", getpid(), pthread_self());

	sleep(1);
	printf("I will out\n");
	pthread_exit(NULL);
	return 0;
}

