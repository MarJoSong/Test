#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
	char strFileName[256] = {0};
	int i=0;

	while(1)
	{
		memset(strFileName, 0x00, sizeof(strFileName));
		//open函数不能递归创建文件夹，执行前一定要保证路径存在
		sprintf(strFileName, "%s/log/nohup.%ld", getenv("HOME"), time(NULL));
		
		int fd = open(strFileName, O_RDONLY|O_CREAT, 0664);
		if(fd<0)
		{
			perror("open err");
			exit(1);
		}
		close(fd);
		printf("已创建 %d 个文件\n", ++i);
		sleep(5);
	}
	return 0;
}

