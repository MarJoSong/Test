#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

int main()
{
	pid_t pid = fork();
	if(pid==0)
	{
		printf("I am child, pid = %d, ppid = %d\n", getpid(), getppid());
		sleep(2);
		while(1)//尝试注释此行
		{
			printf("I am chile, come to beat me\n");
			sleep(1);
		}
		//return 101;
		exit(102);
		//以上都是正常退出的返回值
	}
	if(pid>0)
	{
		printf("I am father, pid = %d, ppid = %d\n", getpid(), getppid());
		int status;
		pid_t sonpid = wait(&status);
		printf("wait ol, sonpid = %d, forkpid = %d\n", sonpid, pid);
		if(WIFEXITED(status))
		{
			printf("child exit with %d\n", WEXITSTATUS(status));
		}
		if(WIFSIGNALED(status))
		{
			printf("child killed by %d\n", WTERMSIG(status));
		}
	}
	while(1)
	{
		sleep(1);
	}
	return 0;
}
