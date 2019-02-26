#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

int main()
{
    int fd = socket(AF_LOCAL, SOCK_STREAM, 0);
    if(fd==-1)
    {
        perror("socket error");
        exit(1);
    }

    unlink("client.socket");

    struct sockaddr_un client;
    client.sun_family = AF_LOCAL;
    strcpy(client.sun_path, "client.socket");
    int ret = bind(fd, (struct sockaddr*)&client, sizeof (client));
    if(ret==-1)
    {
        perror("bind error");
        exit(1);
    }

    struct sockaddr_un serv;
    serv.sun_family = AF_LOCAL;
    strcpy(serv.sun_path, "server.socket");
    ret = connect(fd, (struct sockaddr*)&serv, sizeof (serv));
    if(ret==-1)
    {
        perror("connect error");
        exit(1);
    }

    while(1)
    {
        char buf[1024] = {0};
        ret = recv(fd, buf, sizeof (buf), 0);
        if(ret==-1)
        {
            perror("recv error");
            exit(1);
        }
        else if (ret==0)
        {
            printf("客户端已经断开了连接\n");
            break;
        }
        else
        {
            printf("接收到的数据为: %s\n", buf);
            for(int i=0; i<ret; ++i)
            {
                buf[i] = toupper(buf[i]);
            }
            send(fd, buf, strlen(buf)+1, 0);
        }
    }

    close(fd);

    return 0;
}

