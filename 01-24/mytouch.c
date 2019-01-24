/************************************************************************
  > File Name: mytouch.c
  > Author: syh
  > Mail: 769200142@qq.com 
  > Created Time: 2019年01月24日 星期四 11时03分45秒
 ************************************************************************/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char* argv[])
{
	if(argc<2)
	{
		printf("Usage: ./mytouch filename1 filename2 ..\n");
		return -1;
	}

	for(int i=argc; i>0; --i)
	{
		int fd = open(argv[i], O_RDONLY|O_CREAT, 0666);
		close(fd);
	}
	return 0;
}
