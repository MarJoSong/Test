#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	int n = 5;
	int i = 5;
	pid_t pid = 0;
	printf("In father process, pid = %d, father process pid = %d\n",getpid(), getppid());
	for(i=0; i<5; ++i)
	{
		pid = fork();
		if(pid==0)
		{
			printf("In Child process, pid = %d, father process pid = %d\n",getpid(), getppid());
			break;
		}
	}
	sleep(i);
	if(i<5)
	{
			printf("I am Child, ready to exit, pid = %d, father process pid = %d\n",getpid(), getppid());
	}
	else
	{
			
			printf("I am father, ready to exit, pid = %d, father process pid = %d\n",getpid(), getppid());
	}
}
