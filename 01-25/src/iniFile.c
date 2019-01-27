/************************************************************************
  > File Name: iniFile.c
  > Author: syh
  > Mail: 769200142@qq.com 
  > Created Time: 2019年01月25日 星期五 09时50分39秒
 ************************************************************************/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	if(argc!=2)
	{
		printf("Usage: ./iniFile filename\n");
		return -1;
	}
	int fd = open(argv[1], O_CREAT|O_RDWR, 0664);
	if(-1==fd)
	{	
		printf("perror!\n");
		return -1;
	}
	int ret = lseek(fd, 1023, SEEK_END);
	if(-1==ret)
	{
		printf("lseek error!\n");
		return -1;
	}
	write(fd, "a", 1);
	int len = lseek(fd, 0, SEEK_END);
	printf("sizeof %s is %d\n",argv[1], len);
	close(fd);
}
