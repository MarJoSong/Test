/************************************************************************
  > File Name: creat_write.c
  > Author: syh
  > Mail: 769200142@qq.com 
  > Created Time: 2019年01月24日 星期四 18时11分11秒
 ************************************************************************/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	if(argc!=2)
	{
		printf("Usage: ./creat filename\n");
		return -1;
	}
	int fd = open(argv[1], O_CREAT|O_RDWR, 0666);
	write(fd, "HelloWorld\n", 11);

	char buf[256] = {0};
	lseek(fd, 0, SEEK_SET);
	int ret = read(fd, buf, sizeof(buf));

	if(ret){
		write(STDOUT_FILENO, buf, ret);
	}
	close(fd);
	return 0;
}
