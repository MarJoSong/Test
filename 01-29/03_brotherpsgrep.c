#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int i;
	int status;
	int fd[2];
	pipe(fd);
	pid_t pid = fork();
	if(pid==0)
	{
		//标准输出重定向到管道写端
		dup2(fd[1], STDOUT_FILENO);
		execlp("ps", "ps", "aux", NULL);
	}
	if(pid>0)
	{
		pid_t pid = fork();
		if(pid==0)
		{
			dup2(fd[0], STDIN_FILENO);
			execlp("grep", "grep", "bash", NULL);
		}
		if(pid>0)
		{
			wait(&status);
		}
	}
	return 0;
}
