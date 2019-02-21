#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <error.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

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

	struct sockaddr_in client_addr;
	socklen_t cli_len = sizeof(client_addr);

	//最大的文件描述符
	int maxfd = lfd;
	//文件描述符读集合
	fd_set reads, temp;
	//init
	FD_ZERO(&reads);
	FD_SET(lfd, &reads);

	while(1)
	{
		//委托内和进行IO检测
		temp = reads;
		int ret = select(maxfd+1, &temp, NULL, NULL, NULL);
		if(ret==-1)
		{
			perror("select err");
			exit(1);
		}
		//客户端发起了新连接
		if(FD_ISSET(lfd, &temp))
		{
			//接受连接请求 - accept不阻塞
			int cfd = accept(lfd, (struct sockaddr*)&client_addr, &cli_len);
			if(cfd==-1)
			{
				perror("accept err");
				exit(1);
			}
			char ip[64];
			printf("新客户端连接: %s, Port: %d\n", 
						inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, ip, sizeof(ip)), ntohs(client_addr.sin_port));

			//将cfd加入到待检测的读集合中 - 下一次就可以检测到了
			FD_SET(cfd, &reads);
			//更新最大的文件描述符
			maxfd = maxfd<cfd ? cfd:maxfd;
		}
		//已经连接的客户端有数据到达
		for(int i=lfd+1; i<=maxfd; ++i)
		{
			if(FD_ISSET(i, &temp))
			{
				char buf[1024];
				memset(buf, 0x00, 1024);
				int len = recv(i, buf, sizeof(buf), 0);
				if(len == -1)
				{
					perror("recv err");
					exit(1);
				}
				else if(len == 0)
				{
					printf("客户端已经断开了连接\n");
					close(i);
					//从读集合中删掉
					FD_CLR(i, &reads);
				}
				else
				{
					printf("接收到的数据: %s\n", buf);
					send(i, buf, strlen(buf), 0);
				}
			}
		}
	}

	close(lfd);
	return 0;
}
