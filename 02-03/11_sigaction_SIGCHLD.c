#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void catch_sig(int num)
{
	pid_t spid = waitpid(-1, NULL, WNOHANG);
	printf("ppid %d has been killed\n", spid);
}

int main(int argc, char* argv[])
{
	int i;
	pid_t pid;
	for(i=0;i<10;++i)
	{
		pid = fork();
		if(pid==0)
		{
			break;
		}
	}
	if(i==10)
	{
		struct sigaction sig;
		sig.sa_flags = 0;
		sig.sa_handler = catch_sig;
		sigemptyset(&sig.sa_mask);
		sigaction(SIGCHLD, &sig, NULL);
		while(1)
		{
			sleep(1);
			//如果注释sleep，会同时发出多个SIGCHLD信号，可能产生屏蔽现象，导致产生僵尸进程
		};
	}
	if(i<10)
	{
		printf("I am child, mypid = %d\n", getpid());
		sleep(i);
	}
	return 0;
}

