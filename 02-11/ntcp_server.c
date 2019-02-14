#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <error.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <errno.h>

void recycle(int num)
{
	pid_t pid = getpid();
	while(waitpid(-1, NULL, WNOHANG)>0)
	{
		printf("子进程 %d 断开了连接\n", pid);
	}
}


int main(int argc, char* argv[])
{
	if(argc!=2)
	{
		printf("eg: %s port\n", argv[0]);
		exit(1);
	}

	struct sockaddr_in serv_addr;
	socklen_t serv_len = sizeof(serv_addr);
	int port = atoi(argv[1]);

	//创建套接字
	int lfd = socket(AF_INET, SOCK_STREAM, 0);

	//初始化服务器
	memset(&serv_addr, 0, serv_len);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(port);

	//绑定IP和端口
	bind(lfd, (struct sockaddr*)&serv_addr, serv_len);

	//设置同时监听的最大个数
	listen(lfd, 36);
	printf("Start to accept......\n");

	//注册CHLD信号回收子进程
	struct sigaction sig;
	sig.sa_handler = recycle;
	sig.sa_flags = 0;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGCHLD, &sig, NULL);

	struct sockaddr_in client_addr;
	socklen_t cli_len = sizeof(client_addr);

	while(1)
	{
		//父进程接收连接请求,判断返回值
		int cfd = accept(lfd, (struct sockaddr*)&client_addr, &cli_len);
		if(cfd==-1 && errno == EINTR)
		{
			cfd = accept(lfd, (struct sockaddr*)&client_addr, &cli_len);
		}
		//创建子进程
		pid_t pid = fork();
		if(pid<0)
		{
			perror("fork err");
			exit(1);
		}
		else if(pid>0)
		{
			close(cfd);
			printf("accept successful!!!\n");
			char ipbuf[64] = {0};
			printf("client IP: %s, port: %d 加入了连接\n", inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, ipbuf, sizeof(ipbuf)), ntohs(client_addr.sin_port));
			continue;
		}


		//子进程内通信
		close(lfd);
		while(1)
		{
			char buf[1024];
			memset(buf, 0x00, sizeof(buf));
			int ret = read(cfd, buf, sizeof(buf));
			if(ret==0)
			{
				printf("客户端断开了连接\n");
				exit(0);
			}
			else if(ret<0)
			{
				perror("read err");
				exit(1);
			}
			for(int i=0;i<ret;++i)
			{
				buf[i] = toupper(buf[i]);
			}
			write(cfd, buf, ret);
		}
	}

	close(lfd);
	return 0;
}
