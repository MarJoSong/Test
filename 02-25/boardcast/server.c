#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    //创建广播套接字，协议为UDP
    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(fd==-1)
    {
        perror("socket error");
        exit(1);
    }

    //绑定服务器主机IP和端口
    struct sockaddr_in serv;
    memset(&serv, 0, sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_port = htons(8787);
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    int ret = bind(fd, (struct sockaddr*)&serv, sizeof(serv));
    if(ret==-1)
    {
        perror("bind error");
        exit(1);
    }

    //初始化广播网段和端口信息
    struct sockaddr_in client;
    memset(&client, 0, sizeof(client));
    client.sin_family = AF_INET;
    client.sin_port = htons(6767);
    //使用管波地址向客户端发数据,"255.255.255.255"为全局广播    
    //inet_pton(AF_INET, "255.255.255.255", &client.sin_addr.s_addr);
    inet_pton(AF_INET, "172.116.175.255", &client.sin_addr.s_addr);

    //服务开放广播权限
    int flag = 1;
    setsockopt(fd, SOL_SOCKET, SO_BROADCAST, &flag, sizeof(flag));

    //通信
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
        printf("服务器向外广播 %d 次\n", num);
        sleep(1);
    }
    close(fd);

    return 0;
}

