#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char* argv[])
{
	sigset_t pend, sigproc;
	sigemptyset(&sigproc);
	sigaddset(&sigproc, SIGINT);
	sigaddset(&sigproc, SIGQUIT);
	sigaddset(&sigproc, SIGKILL);//kill信号无法拦截和阻塞
	sigprocmask(SIG_BLOCK, &sigproc, NULL);

	int i;
	while(1)
	{
		sigpending(&pend);
		for(i=1;i<32;++i)
		{
			if(sigismember(&pend,i)==1)
				printf("1");
			else
			{
				printf("0");
			}
		}
		printf("\n");
		sleep(1);
	}
	return 0;
}

