#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if(argc!=2)
	{
		printf("Usage: ./cmd filename\n");
		exit(1);
	}
	printf("begin open...\n");
	int fd = open(argv[1], O_RDONLY);
	printf("end open...\n");
	char buf[20];
	int ret;
	while(1)
	{
		memset(buf, 0, sizeof(buf));
		ret = read(fd, buf,sizeof(buf));
		if(ret>0)
		{
			printf("%s\n",buf);
		}
	}
	close(fd);
	return 0;
}

