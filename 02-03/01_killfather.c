#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char* argv[])
{
	int i;
	for(i=0; i<5; ++i)
	{
		pid_t pid = fork();
		if(pid==0)
		{
			break;
		}
	}
	if(i==2)
	{
		sleep(1);
		printf("I am child, I will kill father after 5 seconds\n");
		sleep(5);
		kill(getppid(), SIGKILL);
		while(1);
	}else if(i==5)
	{
		while(1)
		{
			printf("I am father, I am very happy\n");
			sleep(1);
		}
	}
	return 0;
}

