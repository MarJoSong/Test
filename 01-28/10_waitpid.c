#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int main()
{
	pid_t pid = fork();

	if(pid==0)
	{
		printf("I am a child, pid = %d\n",getpid());
		sleep(2);
	}
	if(pid>0)
	{
		printf("I am a parent, pid = %d\n", getpid());
		int ret;
		while((ret=waitpid(-1, NULL, WNOHANG))==0)
		{
			sleep(1);
		}
		printf("ret = %d\n", ret);
		ret = waitpid(-1,NULL,WNOHANG);
		if(ret<0)
		{
			perror("wait err");
		}
		while(1)
		{
			sleep(1);
		}
	}
	return 0;
}
