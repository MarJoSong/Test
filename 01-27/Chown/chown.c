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

//需要root权限
int main(int argc, char* argv[])
{
	//第二，第三参数为uid，可使用cat /etc/passwd | grep user查询，
	chown("hello", 0, 0);
	return 0;
}

