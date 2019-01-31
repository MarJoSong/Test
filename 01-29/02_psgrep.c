#include <stdio.h>
#include <unistd.h>

int main()
{
	int fd[2];
	pipe(fd);
	pid_t pid = fork();
	if(pid==0)
	{
		close(fd[0]);
		//标准输出重定向到管道写端
		dup2(fd[1], STDOUT_FILENO);
		execlp("ps", "ps", "aux", NULL);
	}
	if(pid>0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		execlp("grep", "grep", "bash", NULL);
	}
	return 0;
}
