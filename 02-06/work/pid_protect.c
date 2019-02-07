#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

int fd;
int count = 0;
void catch_sig(int num)
{
	char buf[256];
	memset(buf, 0x00, 256);
	time_t tim = time(NULL);
	struct tm* tim_now = localtime(&tim);
	sprintf(buf, "%02d:%02d %02d:%02d:%02d pid_protect [%d]:第 %d 次记录\n", tim_now->tm_mon+1, tim_now->tm_mday, tim_now->tm_hour, tim_now->tm_min, tim_now->tm_sec, getpid(), ++count);
	write(fd, buf, strlen(buf));
}

int main(int argc, char* argv[])
{
	//创建子进程
	pid_t pid = fork();
	//父进程退出
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
	close(0);close(1);close(2);
	//执行核心代码
	signal(SIGALRM, catch_sig);
	char fileName[128];
	memset(fileName,0x00, 128);
	time_t tim = time(NULL);
	struct tm* tim_now = localtime(&tim);
	sprintf(fileName, "%s/log/%s.%4d%02d", getenv("HOME"), "pid_protect", tim_now->tm_year+1900, tim_now->tm_mon+1);
	fd = open(fileName, O_RDWR|O_CREAT|O_TRUNC, 0664);
	if(fd==-1)
	{
		perror("open err");
		exit(1);
	}
	struct itimerval myit = {{5,0},{5,0}};
	setitimer(ITIMER_REAL, &myit,NULL);
	while(1)
	{
		sleep(1);	
	}
	return 0;
}

