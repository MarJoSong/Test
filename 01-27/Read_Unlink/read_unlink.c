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
#include <unistd.h>

int main(int argc, char* argv[])
{
	char size[32]={0};
	//只能读软链接
	readlink("hello.soft", size, sizeof(size));
	printf("Origin file is %s\n",size);

	//可以释放软硬链接,甚至是文件
	unlink("hello.hard");
	unlink("hello.soft1");
	return 0;
}

