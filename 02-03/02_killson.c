#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char* argv[])
{
	int i;
	pid_t pid2,pid;
	for(i=0; i<3; ++i)
	{
		pid = fork();
		if(pid==0)
		{
			break;
		}
		if(i==2)
		{
			pid2 = pid;
		}
	}
	if(i<3)
	{
		while(1)
		{
			printf("I am child %d, I am happy\n", getpid());
			sleep(3);
		}
	}else if(i==3)
	{
		printf("I am father, I will kill one of my son after 3 seconds\n");
		sleep(3);
		kill(pid2, SIGKILL);
		while(1)
		{
			sleep(1);
		}
	}
	return 0;
}

