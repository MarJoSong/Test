#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int beginNum = 0;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct ProtAndConNode{
	int num;
	struct ProtAndCosNode* next;
}pacNode;
pacNode* head = NULL;

void* produce_thr(void* arg)
{
	while(1)
	{
		pacNode* newNode = malloc(sizeof(pacNode));
		newNode->num = ++beginNum;
		printf("[+] %s  线程号 %lu  产生 %d 号资源\n", __FUNCTION__, pthread_self(), newNode->num);
		pthread_mutex_lock(&mutex);
		newNode->next = head;
		head = newNode;
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&cond);
		sleep(rand()%2);
	}
	return NULL;
}

void* consume_thr(void* arg)
{
	pacNode* proc;
	while(1)
	{
		pthread_mutex_lock(&mutex);
		while(head==NULL)
		{
			pthread_cond_wait(&cond,&mutex);
		}
		proc = head;
		head = head->next;
		printf("[-] %s  进程号 %lu  消耗 %d 号资源\n", __FUNCTION__, pthread_self(), proc->num);
		pthread_mutex_unlock(&mutex);
		free(proc);
		sleep(rand()%4);
	}
}

int main(int argc, char* argv[])
{
	pthread_t tid[4];
	pthread_create(&tid[0], NULL, produce_thr, NULL);
	pthread_create(&tid[1], NULL, consume_thr, NULL);
	pthread_create(&tid[2], NULL, consume_thr, NULL);
	pthread_create(&tid[3], NULL, consume_thr, NULL);

	int i;
	for(i=0;i<4;++i)
	{
		pthread_join(tid[i], NULL);
	}

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);

	return 0;
}

