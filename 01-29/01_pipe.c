#include <stdio.h>
#include <unistd.h>

int main()
{
	int fd[2];
	pipe(fd);
	pid_t pid = fork();
	if(pid==0)
	{
		write(fd[1], "hello\n", 6);
		close(fd[0]);
		close(fd[1]);
	}
	if(pid>0)
	{
		close(fd[1]);
		char buf[32]={0};
		//read读设备(管道)时堵塞
		while(1)
		{
			int ret = read(fd[0], buf, sizeof(buf));
			if(ret>0)
			{
				write(STDOUT_FILENO, buf, ret);
			}
			if(ret==0)
			{
				printf("Write over\n");
				break;
			}
			sleep(2);
		}
	}
	return 0;
}
