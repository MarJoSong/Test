#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void* thr(void* arg)
{
	printf("I am a new thread, pid = %d, tid = %d\n", getpid(), pthread_self());
	sleep(5);
	printf("I am the new thread, pid = %d, tid = %d\n", getpid(), pthread_self());
	return (void*)100;//等同于pthread_exit((void*)100)
}

int main(int argc, char* argv[])
{
	pthread_t tid;
	pthread_create(&tid, NULL, thr, NULL);
	printf("I am main thread, pid = %d, tid = %d\n", getpid(), pthread_self());

	void* ret;
	pthread_join(tid, &ret);

	printf("ret exit with %d\n", (int)ret);
	pthread_exit(NULL);//等同于return NULL
}

