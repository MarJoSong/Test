#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

void catch_sig(int num)
{
	if(num==20)
	{
		printf("老子就要呆顶层\n");
	}
	if(num==3)
	{
		printf("退不掉，退不掉\n");
	}
}


int main(int argc, char* argv[])
{
	signal(SIGTSTP, catch_sig);
	while(1)
	{
		printf("Who can kill me!\n");
		sleep(1);
	}
	return 0;
}

