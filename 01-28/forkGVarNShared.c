#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	int var = 100;
	pid_t pid = 0;
	pid = fork();
	if(pid==0)
	{
		printf("In child, var=%d\n",var);
		var = 1001;
		printf("In child, var=%d\n",var);
		sleep(3);
		printf("In child, var=%d\n",var);
	}
	if(pid>0)
	{
		sleep(1);
		printf("In parent, var=%d\n",var);
		var = 3001;
		printf("In parent, var=%d\n",var);
		sleep(5);
		printf("In parent, var=%d\n",var);
	}
	return 0;
}
