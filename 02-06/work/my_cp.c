#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <pthread.h>

#define _THR_CNT_ 5

void* thr_cp(void* arg);

int i;
void* memsrc = NULL,* memdes = NULL;
unsigned long cpBlock = 0,cpExtre = 0;

int main(int argc, char* argv[])
{
	//检测输入参数
	if(argc!=3)
	{
		printf("Usage: ./mycp srcfile desfile\n");
		exit(1);
	}

	//获取文件大小
	struct stat st;

	if(stat(argv[1], &st)==-1)
	{
		perror("stat err");
		exit(1);
	}
	unsigned long lfileSize = st.st_size;

	//打开文件
	int fdsrc = open(argv[1], O_RDONLY);
	int fddes = open(argv[2], O_RDWR|O_CREAT|O_TRUNC, 0666);
	ftruncate(fddes, lfileSize);
	if(fdsrc<0 || fddes<0)
	{
		printf("opne file %s or %s err\n", argv[1], argv[2]);
		exit(1);
	}

	//建立映射区
	memsrc= mmap(NULL, lfileSize, PROT_READ, MAP_PRIVATE, fdsrc, 0);
	if(memsrc == MAP_FAILED)
	{
		perror("map srcfile err");
		exit(1);
	}
	memdes= mmap(NULL, lfileSize, PROT_READ|PROT_WRITE, MAP_SHARED, fddes, 0);
	if(memdes == MAP_FAILED)
	{
		perror("map desfile err");
		exit(1);
	}

	//为线程提前划分拷贝区块
	cpBlock = lfileSize / _THR_CNT_;
	cpExtre = lfileSize % _THR_CNT_;

	//建立线程
	pthread_t tid[_THR_CNT_];
	for(i=0; i<_THR_CNT_; ++i)
	{
		pthread_create(&tid[i], NULL, thr_cp, (void*)i);
	}

	//回收进程
	for(i=0; i<_THR_CNT_; ++i)
	{
		pthread_join(tid[i], NULL);
	}

	//接除映射
	munmap(memsrc, lfileSize);
	munmap(memdes, lfileSize);

	return 0;
}

void* thr_cp(void* arg)
{
	int i = (int)arg;
	if(i == _THR_CNT_ - 1)
	{
		memcpy(memdes+i*cpBlock, memsrc+i*cpBlock, cpBlock+cpExtre);
	}
	else
	{
		memcpy(memdes+i*cpBlock, memsrc+i*cpBlock, cpBlock);
	}
	pthread_exit(NULL);
}
