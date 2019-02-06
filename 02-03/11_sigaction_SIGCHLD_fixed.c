#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void catch_sig(int num)
{
	pid_t spid;
	while((spid=waitpid(-1, NULL, WNOHANG))>0)
	{
		printf("ppid %d has been killed\n", spid);
	}
}

int main(int argc, char* argv[])
{
	int i;
	pid_t pid;

	//创建子进程前先屏蔽SIGCHLD信号
	sigset_t myset,oldset;
	sigemptyset(&myset);
	sigaddset(&myset, SIGCHLD);
	sigprocmask(SIG_BLOCK, &myset, &oldset);//oldset用于保留现场

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
		sleep(2);//如果信号注册晚于子进程死亡，会接收不到信号，可提前设置屏蔽
		struct sigaction sig;
		sig.sa_flags = 0;
		sig.sa_handler = catch_sig;
		sigemptyset(&sig.sa_mask);
		sigaction(SIGCHLD, &sig, NULL);

		//信号注册后关闭屏蔽

		sigprocmask(SIG_SETMASK, &oldset, NULL);

		while(1)
		{
			sleep(1);
		};
	}
	if(i<10)
	{
		printf("I am child, mypid = %d\n", getpid());
		//sleep(i);
		//如果注释sleep，会同时发出多个SIGCHLD信号，可能产生屏蔽现象，导致产生僵尸进程
	}
	return 0;
}

