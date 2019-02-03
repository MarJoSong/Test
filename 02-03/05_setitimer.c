#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	struct itimerval myit = {{0, 0} ,{3, 0}};
	setitimer(ITIMER_REAL, &myit, NULL);
	while(1)
	{
		printf("Who can kill me!\n");
		sleep(1);
	}
	return 0;
}

