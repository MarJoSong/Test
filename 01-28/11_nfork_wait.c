#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int n=5;
	int i=0;
	pid_t pid;
	for(i=0; i<5; ++i)
	{
		pid = fork();
		if(pid==0)
		{
			printf("I am child, pid = %d\n", getpid());
			break;
		}
	}
	sleep(i);
	if(i==5)
	{
		for(i=0; i<5; ++i)
		{
			pid_t wpid = wait(NULL);
			printf("wpid = %d\n", wpid);
		}
		while(1)
		{
			sleep(1);
		}
	}
}
