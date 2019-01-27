/************************************************************************
    > Author: syh
    > File type: C Source code
    > Mail: 769200142@qq.com 
    > Environment: Linux && Ubuntu 18.04
    > Tool: Vim && Gcc 
************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	int fd = open("hello", O_WRONLY|O_CREAT, 0666);
	unlink("hello");
	int ret = write(fd, "world",5);
	if(ret>0)
	{
		printf("write ok!%d\n", ret);
	}
	if(ret<0)
	{
		perror("write err\n");
	}
	close(fd);
	return 0;
}

