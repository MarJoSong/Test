/************************************************************************
    > Author: syh
    > File type: C Source code
    > Mail: 769200142@qq.com 
    > Environment: Linux && Ubuntu 18.04
    > Tool: Vim && Gcc 
************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
	//硬链接
	link("hello", "hello.hard");
	//软链接
	symlink("hello", "hello.soft");
	return 0;
}

