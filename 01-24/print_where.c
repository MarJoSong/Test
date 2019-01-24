/************************************************************************
    > File Name: print_where.c
    > Author: syh
    > Mail: 769200142@qq.com 
    > Created Time: 2019年01月24日 星期四 10时18分56秒
************************************************************************/
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	close(1);
	int fd = open("1.log", O_CREAT|O_TRUNC|O_WRONLY, 0644);

	printf("hello world\n");
	fflush(stdout);
	close(fd);
	return 0;	
}
