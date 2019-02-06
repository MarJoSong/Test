#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* thr(void* arg)
{
	printf("I am a new thread, pid = %d, pthread = %lu\n", getpid(), pthread_self());
	return NULL;
}

int main(int argc, char* argv[])
{
	pthread_t tid;
	int pth = pthread_create(&tid, NULL, thr, NULL);
	printf("I am the main thread, pid = %d, pthread = %lu\n", getpid(), pthread_self());
	sleep(1);	
	return 0;
}

