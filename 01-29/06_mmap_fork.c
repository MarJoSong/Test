#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	//新建文件,调整大小
	int fd = open("test.txt", O_RDWR|O_CREAT|O_TRUNC, 0664);
	ftruncate(fd, 8);	
	//建立映射区
	int* mem = mmap(NULL, 4, PROT_WRITE|PROT_READ, MAP_SHARED, fd, 0);
	if(mem==MAP_FAILED)
	{
		perror("mmap err");
		return -1;
	}
	//fork子进程进行读写
	pid_t pid = fork();
	if(pid==0)
	{
		*mem = 100;
		printf("I am child: *mem = %d\n", *mem);
		sleep(2);
		printf("I am child: *mem = %d\n", *mem);
	}
	if(pid>0)
	{
		sleep(1);
		printf("I am parent: *mem = %d\n", *mem);
		*mem = 1001;
		sleep(3);
		printf("I am parent: *mem = %d\n", *mem);
		//回收子进程
		wait(NULL);
	}
	//关闭文件连接，内存映射，删除临时文件
	close(fd);
	munmap(mem, 4);
	unlink("test.txt");

	return 0;
}

