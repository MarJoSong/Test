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
	//创建监听的套接字
	int lfd = socket(AF_INET, SOCK_STREAM, 0);
	// int  socket(int protofamily, int type, int protocol);//返回sockfd
	//protofamily：即协议域，又称为协议族,有AF_INET(IPV4)、AF_INET6(IPV6)、AF_LOCAL（或称AF_UNIX，Unix域socket）、AF_ROUTE等等
	//type：指定socket类型。常用的socket类型有，SOCK_STREAM、SOCK_DGRAM、SOCK_RAW、SOCK_PACKET、SOCK_SEQPACKET等等
	//protocol：故名思意，就是指定协议。常用的协议有，IPPROTO_TCP、IPPTOTO_UDP、IPPROTO_SCTP、IPPROTO_TIPC等，它们分别对应TCP传输协议、UDP传输协议、STCP传输协议、TIPC传输协议
	if(lfd == -1)
	{
		perror("socket err");
		exit(1);
	}

	//lfd与本地IP Port绑定
	//int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
	//sockfd：即socket描述字，它是通过socket()函数创建了，唯一标识一个socket
	//addr：一个const struct sockaddr *指针，指向要绑定给sockfd的协议地址。这个地址结构根据地址创建socket时的地址协议族的不同而不同，如ipv4对应的是： struct sockaddr_in, ipv6对应的是： struct sockaddr_in6
	//addrlen：对应的是地址的长度
	struct sockaddr_in server;
	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(8888);
	server.sin_addr.s_addr = htonl(INADDR_ANY);

	int ret = bind(lfd, (struct sockaddr*)&server, sizeof(server));
	if(ret == -1)
	{
		perror("bind err");
		exit(1);
	}
	
	//设置监听
	ret = listen(lfd, 20);
	//listen函数的第一个参数即为要监听的socket描述字，第二个参数为相应socket可以排队的最大连接个数
	if(ret == -1)
	{
		perror("listen err");
		exit(1);
	}
	
	//等待并接收连接请求
	struct sockaddr_in client;
	socklen_t len = sizeof(client);
	int cfd = accept(lfd, (struct sockaddr*)&client, &len);
	//参数sockfd就是上面解释中的监听套接字，这个套接字用来监听一个端口，当有一个客户与服务器连接时，它使用这个一个端口号，而此时这个端口号正与这个套接字关联。当然客户不知道套接字这些细节，它只知道一个地址和一个端口号。
	//参数addr是一个结果参数，它用来接受一个返回值，这返回值指定客户端的地址，当然这个地址是通过某个地址结构来描述的，用户应该知道这一个什么样的地址结构。如果对客户的地址不感兴趣，那么可以把这个值设置为NULL。
	//参数len如同大家所认为的，它也是结果的参数，用来接受上述addr的结构的大小的，它指明addr结构所占有的字节个数。同样的，它也可以被设置为NULL。
	if(cfd == -1)
	{
		perror("accept err");
		exit(1);
	}
	//accept默认会阻塞进程，直到有一个客户连接建立后返回，它返回的是一个新可用的套接字，这个套接字是连接套接字。
	
	printf("accept successful!!!\n");
	char ipbuf[64] = {0};
	printf("client IP: %s, port: %d\n", inet_ntop(AF_INET, &client.sin_addr.s_addr, ipbuf, sizeof(ipbuf)), ntohs(client.sin_port));

	//一直通信
	while(1)
	{
		//先接收数据
		char buf[1024]  = {0};
		int len = read(cfd, buf, sizeof(buf));
		if(len == -1)
		{
			perror("read err");
			exit(1);
		}
		else if(len == 0)
		{
			printf("客户端已经断开了连接\n");
			close(cfd);
			break;
		}
		else
		{
			printf("recv buf: %s\n", buf);
			//转换 - 小写 - 大写
			for(int i=0; i<len; ++i)
			{
				buf[i] = toupper(buf[i]);
			}
			printf("send buf: %s\n", buf);
			write(cfd, buf, len);
		}
	}

	close(lfd);

	return 0;
}

