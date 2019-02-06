#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void* thr(void* arg)
{
	//线程里应该有执行代码，否则可能杀不掉
	while(1)
	{
		printf("I am a new thread, pid = %d, tid = %d\n", getpid(), pthread_self());
		sleep(1);
	}
	return (void*)100;//等同于pthread_exit((void*)100)
}

int main(int argc, char* argv[])
{
	printf("I am main thread, pid = %d, tid = %d\n", getpid(), pthread_self());
	pthread_t tid;
	pthread_create(&tid, NULL, thr, NULL);

	sleep(5);
	pthread_cancel(tid);//杀死线程时线程返回值为-1

	void* ret;
	pthread_join(tid, &ret);

	printf("ret exit with %d\n", (int)ret);
	pthread_exit(NULL);//等同于return NULL
}

