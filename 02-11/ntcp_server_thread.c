#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <error.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>

//自定义回调函数参数结构体
typedef struct sockInfo
{
	int cfd;
	struct sockaddr_in addr;
	pthread_t id;
}SockInfo;

//主线程处理函数
void* worker(void* arg)
{
	SockInfo* info = (SockInfo*)arg;
	char ip[64];
	memset(ip, 0x00, sizeof(ip));
	char buf[1024];
	//通信
	while(1)
	{
		printf("client IP: %s, port: %d\n", inet_ntop(AF_INET, &info->addr.sin_addr.s_addr, ip, sizeof(ip)),
				ntohs(info->addr.sin_port));
		memset(buf, 0x00, sizeof(buf));
		int len = read(info->cfd, buf, sizeof(buf));
		if(len == -1)
		{
			perror("read err\n");
			pthread_exit(NULL);
		}
		else if(len == 0)
		{
			printf("客户端已经断开了连接\n");
			close(info->cfd);
			info->cfd = -1;
			break;
		}
		else
		{
			printf("recv buf: %s\n", buf);
			for(int i=0; i<len; ++i)
			{
				buf[i] = toupper(buf[i]);
			}
			write(info->cfd, buf, len);
		}
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

	int i = 0;
	SockInfo info[256];
	socklen_t cli_len = sizeof(struct sockaddr_in);
	//规定cfd == -1	
	for(;i<sizeof(info)/sizeof(info[0]);++i)
	{
		info[i].cfd = -1;
	}

	while(1)
	{
		//选一个未被使用的最小的文件描述符
		for(i=0;i<sizeof(info)/sizeof(info[0]);++i)
		{
			if(info[i].cfd==-1)
			{
				break;
			}
		}
		if(256 == i)
		{
			break;
		}

		//主线程等待接收连接请求
		info[i].cfd = accept(lfd, (struct sockaddr*)&info[i].addr, &cli_len);

		//创建子线程 - 通信
		pthread_create(&info[i].id, NULL, worker, &info[i]);
		//设置线程分离
		pthread_detach(info[i].id);
	}

	close(lfd);
	//只退出主线程
	pthread_exit(NULL);
	return 0;
}
