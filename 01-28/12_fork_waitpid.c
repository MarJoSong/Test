#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
	int i;
	int n=5;
	pid_t pid;
	for(i=0;i<5;++i)
	{
		pid = fork();
		if(pid==0)
		{
			break;
		}
	}
	if(i<5)
	{
		//sleep(i);
		printf("I am a child, i=%d, pid=%d\n", i, getpid());
	}
	if(i==5)
	{
		printf("I am a parent!\n");
		while(1)
		{
			pid_t wpid = waitpid(-1, NULL, WNOHANG);
			if(wpid==-1)
			{
				break;
			}
			else if(wpid > 0)
			{
				printf("waitpid wpid = %d\n", wpid);
			}
		}
		while(1)
		{
			sleep(1);
		}
	}
	return 0;
}
