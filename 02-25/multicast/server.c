#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <net/if.h>

int main()
{
    //创建组播套接字，协议为UDP
    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(fd==-1)
    {
        perror("socket error");
        exit(1);
    }

    //绑定服务器IP和端口
    struct sockaddr_in serv;
    serv.sin_family = AF_INET;
    serv.sin_port = htons(8787);
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    //inet_pton(AF_INET, "0.0.0.0", &serv.sin_addr.s_addr);
    int ret = bind(fd, (struct sockaddr*)&serv, sizeof (serv));
    if(ret==-1)
    {
        perror("bind error");
        exit(1);
    }

    //初始化客户端信息
    struct sockaddr_in client;
    client.sin_family = AF_INET;
    client.sin_port = htons(6767);  //客户端收数据端口
    //发送数据给客户端的组播地址
    inet_pton(AF_INET, "239.0.0.10", &client.sin_addr.s_addr);

    //设置组播结构体
    struct ip_mreqn flag;
    inet_pton(AF_INET, "239.0.0.10", &flag.imr_multiaddr.s_addr);//组播地址
    inet_pton(AF_INET, "0.0.0.0", &flag.imr_address.s_addr);//本地IP
    flag.imr_ifindex =if_nametoindex("wlp3s0");
    //设置组播权限
    setsockopt(fd, IPPROTO_IP, IP_MULTICAST_IF, &flag, sizeof (flag));

    // 通信
    while(1)
    {
        //不断发送数据
        static int num = 0;
        char buf[1024] = {0};
        sprintf(buf, "hello UDP BoardCast count = %d", ++num);
        int ret = sendto(fd, buf, strlen(buf)+1, 0, (struct sockaddr*)&client, sizeof(client));
        if(ret==-1)
        {
            perror("sendto error");
            break;
        }
        printf("服务器向外组播 %d 次\n", num);
        sleep(1);
    }
    close(fd);

    return 0;
}

