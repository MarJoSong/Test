/************************************************************************
  > File Name: mysizeof.c
  > Author: syh
  > Mail: 769200142@qq.com 
  > Created Time: 2019年01月25日 星期五 08时40分54秒
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
		printf("Usage: ./mysizeof filaname\n");
		return -1;
	}
	int fd = open(argv[1], O_RDONLY);
	if(-1==fd)
	{
		printf("%s not found!\n",argv[1]);
		return -1;
	}
	int ret = lseek(fd, 0, SEEK_END);
	printf("size of file is %d\n", ret);
	close(fd);
	return 0;
}
