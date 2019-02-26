#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char* argv[])
{
    if(argc!=3)
    {
        printf("用法: %s [ip] [port]\n", argv[0]);
        exit(1);
    }
    int port = atoi(argv[2]);

    //创建套接字
    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(fd==-1)
    {
        perror("socket error");
        exit(1);
    }

    //绑定服务器IP和端口
    struct sockaddr_in serv;
    serv.sin_family = AF_INET;
    serv.sin_port = htons(port);
    socklen_t len = sizeof(serv);
    inet_pton(AF_INET, argv[1], (struct sockaddr*)&serv);

    //通信
    while(1)
    {
        //发送数据
        char buf[1024] = {0};
        printf("输入要发送的数据: ");
        fgets(buf, sizeof(buf), stdin);
        sendto(fd, buf, strlen(buf)+1, 0, (struct sockaddr*)&serv, len);

        //接收数据
        memset(buf, 0x00, sizeof buf);
        recvfrom(fd, buf, sizeof(buf), 0, NULL, NULL);
        printf("接收到的数据: %s\n", buf);
    }

    close(fd);
    return 0;
}

