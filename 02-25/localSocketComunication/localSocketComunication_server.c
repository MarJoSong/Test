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
    int lfd = socket(AF_LOCAL, SOCK_STREAM, 0);
    if(lfd==-1)
    {
        perror("socket error");
        exit(1);
    }

    unlink("server.socket");

    struct sockaddr_un serv;
    serv.sun_family = AF_LOCAL;
    strcpy(serv.sun_path, "server.socket");
    int ret = bind(lfd, (struct sockaddr*)&serv, sizeof serv);
    if(ret==-1)
    {
        perror("bind error");
        exit(1);
    }

    ret = listen(lfd, 36);
    if(ret==-1)
    {
        perror("listen error");
        exit(1);
    }

    struct sockaddr_un client;
    socklen_t socklen = sizeof client;
    memset(&client, 0x00, socklen); 
    int cfd = accept(lfd, (struct sockaddr*)&client, &socklen);
    if(cfd==-1)
    {
        perror("accept error");
        exit(1);
    }
    printf("======客户端已连接======\n");
    printf("套接字文件为: %s\n",client.sun_path);

    while(1)
    {
        char buf[1024] = {0};
        printf("输入要发送的数据: ");
        //在按下回车之前断开客户端，按下回车后会服务器端会因为收到SIGPIPE信号而中断
        fgets(buf, sizeof (buf), stdin);
        send(cfd, buf, strlen(buf)+1, 0);

        memset(buf, 0, sizeof (buf));
        ret = recv(cfd, buf, sizeof (buf), 0);
        printf("ret = %d\n", ret);
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
        }
    }

    close(lfd);
    close(cfd);

    return 0;
}

