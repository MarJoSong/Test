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
#include <sys/types.h>:

int main(int argc, char* argv[])
{
	char name[128] = {0};
	int fd;
	while(1)
	{
		fd = open("open.txt", O_RDONLY|O_CREAT, 0666);
	}


	return 0;
}

