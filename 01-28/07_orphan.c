#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid = fork();
	if(pid==0)
	{
		while(1)
		{
			printf("I am a child, myPid = %d, parentPid = %d\n", getpid(), getppid());
			sleep(1);
		}
	}
	if(pid>0)
	{
		printf("I am parent, myPid = %d, parentPid = %d\n", getpid(), getppid());
		sleep(5);
		printf("I am parent, I will die\n");
	}
	return 0;
}

