#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <signal.h>

void touchfile(int num)
{
	char strFileName[256] = {0};
	sprintf(strFileName, "Mydeamon.%ld",time(NULL));

	int fd = open(strFileName, O_RDWR|O_CREAT, 0666);

	if(fd<0)
	{
		perror("open err");
		exit(1);
	}
	close(fd);
}

int main(int argc, char* argv[])
{
	//创建子进程，父进程退出
	pid_t pid = fork();
	if(pid>0)
	{
		exit(1);
	}
	//当会长
	setsid();
	//设置掩码
	umask(0);
	//切换目录
	chdir(getenv("HOME"));
	//关闭文件描述符
	//close(0),close(1),close(2);
	//执行核心逻辑
	struct itimerval myit = {{10,0},{5,0}};
	setitimer(ITIMER_REAL, &myit, NULL);
	struct sigaction sig;
	sig.sa_flags = 0;
	sig.sa_handler = touchfile;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGALRM, &sig, NULL);

	while(1)
	{
		sleep(1);
	}

	return 0;
}

