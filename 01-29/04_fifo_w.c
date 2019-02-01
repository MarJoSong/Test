#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
	if(argc!=2)
	{
		printf("Usage: ./cmd filename\n");
		exit(1);
	}
	int i=0;
	char buf[20];
	printf("begin open to write...\n");
	int fd = open(argv[1], O_WRONLY);
	printf("end open...\n");

	while(1)
	{
		memset(buf, 0, sizeof(buf));
		sprintf(buf, "fifo%04d", i++);
		write(fd, buf, strlen(buf));
		sleep(1);
	}
	close(fd);
	return 0;
}

