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
	chdir("TestDir");
	char buf[256];
	getcwd(buf, sizeof(buf));
	printf("buf is [%s]\n", buf);

	int fd = open("temp.txt", O_WRONLY|O_CREAT, 0666);
	write(fd, "helloworld",10);
	close(fd);

	return 0;
}

