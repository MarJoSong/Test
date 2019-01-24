/************************************************************************
  > File Name: mycat.c
  > Author: syh
  > Mail: 769200142@qq.com 
  > Created Time: 2019年01月24日 星期四 11时28分26秒
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
		printf("Usage: ./mycat filename1 filename2 ..\n");
		return -1;
	}

	for(int i=1; i<argc; ++i)
	{
		int fd = open(argv[i], O_RDONLY);

		char buf[256];
		int ret;
		do
		{
			ret = read(fd, buf, sizeof(buf));
			write(STDOUT_FILENO, buf, ret);
		}while(ret!=0);
		close(fd);
	}
	return 0;
}
