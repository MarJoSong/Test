#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <error.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>

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

	//创建epoll树根结点
	int epfd = epoll_create(2000);
	//初始化epoll树
	struct epoll_event ev;
	ev.events = EPOLLIN;
	ev.data.fd = lfd;
	epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &ev);

	struct epoll_event all[2000];
	while(1)
	{
		//使用epoll同志内核fd 文件IO检测
        int ret = epoll_wait(epfd, all, sizeof(all)/sizeof(all[0]), -1);

        //遍历all数组中的前ret个元素
        for(int i=0; i<ret; ++i)
        {
            int fd = all[i].data.fd;
            if(fd==lfd)
            {
                //接受连接请求
                int cfd = accept(lfd, (struct sockaddr*)&client_addr, &cli_len);
                if(cfd==-1)
                {
                    perror("accept err");
                    exit(1);
                }
                //将新得到的cfd挂到树上
                struct epoll_event temp;
                temp.events = EPOLLIN;
                temp.data.fd = cfd;
                epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &temp);
                //打印客户端信息
                char ip[64] = {0};
                printf("新客户端IP: %s, Port: %d\n", inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, ip, sizeof(ip)), ntohs(client_addr.sin_port));
            }
            else
            {
                //处理已连接客户端发送的数据
                if(!all[i].events & EPOLLIN)
                {
                    continue;
                }
                //读数据
                char buf[1024] = {0};
                int len = recv(fd, buf, sizeof(buf), 0);
                if(len==-1)
                {
                    perror("recv err");
                    exit(1);
                }
                else if(len==0)
                {
                    printf("客户端已经断开了连接\n");
                    //fd从epoll上删除
                    epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);
                    //close操作要房子DEL之后
                    close(fd);
                }
                else
                {
                    printf("接收到的数据: %s\n", buf);
                    send(fd, buf, strlen(buf), 0);
                }
            }
        }

	}

	close(lfd);
	return 0;
}
