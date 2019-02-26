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

    //绑定客户端自身信息
    struct sockaddr_in client;
    client.sin_family = AF_INET;
    client.sin_port = htons(6767);
    inet_pton(AF_INET, "0.0.0.0", &client.sin_addr.s_addr);
    //client.sin_addr.s_addr = htonl(INADDR_ANY);
    int ret = bind(fd, (struct sockaddr*)&client, sizeof(client));
    if(ret==-1)
    {
        perror("bind error");
        exit(1);
    }

    //加入到组播地址
    struct ip_mreqn flag;
    inet_pton(AF_INET, "239.0.0.10", &flag.imr_multiaddr.s_addr);
    inet_pton(AF_INET, "0.0.0.0", &flag.imr_address.s_addr);
    flag.imr_ifindex =if_nametoindex("wlp3s0");
    setsockopt(fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &flag, sizeof (flag));

    // 接收数据
    while(1)
    {
        char buf[1024] = {0};
        int len = recvfrom(fd, buf, sizeof(buf), 0, NULL, NULL);
        if(len==-1)
        {
            perror("recvfrom error");
            exit(1);
        }
        printf("收到组播，内容为: %s\n", buf);
    }
    close(fd);

    return 0;
}
