#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>

void catch_sig(int num)
{
	printf("Hello World!\n");
}

int main(int argc, char* argv[])
{
	struct itimerval newtim = {{1,0},{1,0}};
	setitimer(ITIMER_REAL, &newtim, NULL);
	struct sigaction sig;
	sig.sa_flags = 0;
	sigemptyset(&sig.sa_mask);
	sig.sa_handler = catch_sig;
	sigaction(SIGALRM, &sig, NULL);
	while(1);
	return 0;
}

