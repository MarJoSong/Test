#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	char buf[20] = {0};
	int fd = open("file1.txt", O_RDWR | O_CREAT, 0666);
	pid_t pid = fork();
	if(pid>0)
	{
		sleep(1);
		write(fd, "AAA", 3);
		printf("parent write: AAA\n");
		sleep(5);

		lseek(fd, 0, SEEK_SET);
		read(fd, buf, 6);
		printf("parent read: %s\n", buf);
	}
	if(pid==0)
	{
		printf("child was forked\n");
		sleep(2);
		lseek(fd, 0, SEEK_SET);
		read(fd, buf, 3);
		printf("child read: %s\n", buf);

		sleep(2);
		write(fd, "BBB", 3);
		printf("child write: BBB\n");
	}
	return 0;
}

