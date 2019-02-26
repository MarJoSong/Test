#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(fd==-1)
    {
        perror("socket error");
        exit(1);
    }

    //绑定自己的IP和端口
    struct sockaddr_in myself;
    myself.sin_family = AF_INET;
    myself.sin_port = htons(6767);
    int ret = bind(fd, (struct sockaddr*)&myself, sizeof(myself));
    if(ret==-1)
    {
        perror("bind error");
        exit(1);
    }

    //接收数据
    while(1)
    {
        char buf[1024] = {0};
        int len = recvfrom(fd, buf, sizeof(buf), 0, NULL, NULL);
        if(len==-1)
        {
            perror("recvfrom error");
            break;
        }
        printf("收到广播，内容为: %s\n", buf);
    }

    close(fd);

    return 0;
}

