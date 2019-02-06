#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>

void catch_sig(int num)
{
	//一下结论不正确
	//程序执行到捕捉函数时，多次发送相同信号，会屏蔽，只会将一个信号放入队列
	int i=0;
	printf("捕捉到 %d 号信号\n",num);
	printf("开始处理");
	fflush(NULL);

	for(;i<5;++i)
	{
		printf(".");
		fflush(NULL);
		sleep(1);
	}
	printf("处理完成!\n");
}

int main(int argc, char* argv[])
{
	struct sigaction sig;
	sig.sa_flags = 0;
	sig.sa_handler = catch_sig;
	sigemptyset(&sig.sa_mask);
	sigaddset(&sig.sa_mask, SIGQUIT);//SIGQUIT会在捕捉函数执行期间临时屏蔽,并进入信号队列
	sigaction(SIGINT, &sig, NULL);//进入捕捉函数后，SIGINT也会被临时屏蔽

	while(1)
	{
		printf("Who can kill me?\n");
		sleep(1);
	}
	return 0;
}

