#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid = fork();
	if(pid==0)
	{
		printf("I am child, pid = %d, ppid = %d\n", getpid(), getppid());
		sleep(1);
		printf("I am child, I will die\n");
	}
	if(pid>0)
	{
		printf("I am father, pid = %d, ppid = %d\n", getpid(), getppid());
		while(1)
		{
			printf("I am happy\n");
			sleep(2);
		}
	}
	return 0;
}

