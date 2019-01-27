/************************************************************************
  > File Name: block.c
  > Author: syh
  > Mail: 769200142@qq.com 
  > Created Time: 2019年01月25日 星期五 10时30分10秒
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
	//int fd = open("/dev/tty", O_RDWR|O_NONBLOCK);
	int fd = open("/dev/tty", O_RDWR);

	//fcntl函数，设置非阻塞
	int flags = fcntl(fd, F_GETFL);
	flags |=O_NONBLOCK;
	fcntl(fd, F_SETFL, flags);

	char buf[256];
	int ret = 0;
	while(1)
	{
		ret = read(fd, buf, sizeof(buf));
		if(ret<0)
		{
			perror("read err:");
			printf("ret is %d\n", ret);
		}
		if(ret)
		{
			printf("buf is %s\n", buf);
		}
		printf("haha\n");
		sleep(1);
	}
	close(fd);
	return 0;
}
