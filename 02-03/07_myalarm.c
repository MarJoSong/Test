#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

unsigned int myalarm(int num)
{
	struct itimerval oldtim, newtim = {{0,0}, {0,0}};
	//间隔num秒，第一次延时5秒
 	newtim.it_value.tv_sec = num;
	setitimer(ITIMER_REAL, &newtim, &oldtim);
	if(num > 0)
	{
		printf("周期定时 %ld 秒，延迟时间 %ld 秒，上一次定时结束时间 %ld 秒 %ld 微秒\n", newtim.it_interval.tv_sec, newtim.it_value.tv_sec, oldtim.it_value.tv_sec, oldtim.it_value.tv_usec);
	}
	if(num == 0)
	{
		printf("取消周期定时，上一次定时结束时间 %ld 秒 %ld 微秒\n", oldtim.it_value.tv_sec, oldtim.it_value.tv_usec);
	}	
}

int main(int argc, char* argv[])
{
	myalarm(6);
	sleep(5);
	myalarm(10);
	while(1)
	{
		sleep(1);
	}
	return 0;
}

