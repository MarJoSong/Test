#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
	int inifd = dup(1);
	int fd = open("test12", O_WRONLY|O_CREAT, 0666);
	//向1写变成向fd写
	dup2(fd, 1);
	printf("Hello World1\n");

	fflush(stdout);

	//向1写还原成向1写
	dup2(inifd, 1);
	printf("Hello World2\n");

	close(fd);
	return 0;
}
