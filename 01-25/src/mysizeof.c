#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	char buf[] = "hello world"; 
	fd = open("lseek.txt", O_RDWR | O_CREAT, 0664);
	if(fd < 0){
		perror("open lseek.txt error");
		exit(1);
	}
	write(fd , buf , strlen(buf));
	//lseek函数会从起始位置开始算到文件末尾,就能求出文件的长度了
	int len = lseek(fd, 0, SEEK_END);
	if(len == -1){
		perror("lseek error");
		exit(1);
	}
	//lseek函数的返回值就是文件的大小
	printf("file len = %d\n", len);
	close(fd);
	return 0;
}
