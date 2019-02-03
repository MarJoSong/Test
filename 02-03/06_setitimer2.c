#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

void catch_sig(int num)
{
	printf("catch %d signal\n", num);
}


int main(int argc, char* argv[])
{
	signal(SIGALRM, catch_sig);
	struct itimerval myit = {{3, 0} ,{5, 0}};//第一次等待5s，之后每隔3s
	setitimer(ITIMER_REAL, &myit, NULL);
	while(1)
	{
		printf("Who can kill me!\n");
		sleep(1);
	}
	return 0;
}

