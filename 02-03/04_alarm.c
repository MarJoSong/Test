#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	alarm(6);
	while(1)
	{
		printf("Come to beat me\n");
		sleep(1);
	}
	return 0;
}

