#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char* argv[])
{
	printf("I will suicide after 3 seconds\n");
	sleep(3);
	//raise(SIGKILL);
	abort();
	return 0;
}

