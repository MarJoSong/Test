#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t pid = fork();
	if(pid==0)
	{
		printf("I am child, pid = %d\n", getpid());
		//执行div程序立马发生浮点数错误，置8号状态位
		//执行array程序立马发生段错误，置11号状态位
		//execl("./div", "div", NULL);
		execl("./array", "array", NULL);
	}
	if(pid>0)
	{
		sleep(2);
		int status;
		pid_t wpid = waitpid(-1, &status, WNOHANG);
		if(WIFEXITED(status))
		{
			printf("child exit with %d\n", WEXITSTATUS(status));
		}
		if(WIFSIGNALED(status))
		{
			printf("child killed by %d\n", WTERMSIG(status));
		}
		printf("I am father, wpid = %d\n", wpid);
	}
	return 0;
}
