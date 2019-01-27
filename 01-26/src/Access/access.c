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
	if(argc!=2)
	{
		printf("Usage: ./%s filename\n", argv[0]);
		return -1;
	}
	if(access(argv[1], R_OK)==0) printf("%s read ok!", argv[1]);
	if(access(argv[1], W_OK)==0) printf("%s write ok!", argv[1]);
	if(access(argv[1], X_OK)==0) printf("%s exec ok!", argv[1]);
	if(access(argv[1], F_OK)==0) printf("%s exist!", argv[1]);
	return 0;
}

