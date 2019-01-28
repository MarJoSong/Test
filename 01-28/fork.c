#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	printf("Begin...\n");
	pid_t pid = fork();
	if(pid<0)
	{
		perror("fork err\n");
		exit(1);
	}
	if(pid==0)
	{
		//第二次返回值等一0，当前进程为子进程
		while(1)
		{
			printf("I am a child, pid = %d, ppid = %d\n", getpid(), getppid());
			sleep(1);
		}
	}
	if(pid>0)
	{
		//第一次返回值>0，当前进程为父进程
		while(1)
		{
			printf("I am a father, childpid = %d, selfpid = %d, ppid = %d\n", pid, getpid(), getppid());
			sleep(1);
		}
	}
	printf("End.....\n");
	return 0;
}

