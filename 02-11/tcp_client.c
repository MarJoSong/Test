#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <error.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    if(argc!=3)
    {
        printf("用法: ./tcp_client ip port\n");
        exit(1);
    }
    int port = atoi(argv[2]);

    //创建套接字
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    //连接服务器
    struct sockaddr_in serv;
    serv.sin_family = AF_INET;
    serv.sin_port = htons(port);
    //serv.sin_addr.s_addr = htonl();
    inet_pton(AF_INET, argv[1], &serv.sin_addr.s_addr);
    connect(fd, (struct sockaddr*)&serv, sizeof(serv));

    //通信
    while(1)
    {
        //发送数据
        char buf[1024];
        printf("请输入要发送的字符串:\n");
        fgets(buf, sizeof(buf), stdin);
        write(fd, buf, strlen(buf));

        //等待接收数据
        int len=recv(fd, buf, sizeof(buf), 0);
        if(len == -1)
        {
            perror("read err");
            exit(1);
        }
        else if(len == 0)
        {
            printf("服务器关闭了连接\n");
            break;
        }
        else
        {
            printf("接收到的数据: ");
            {
                write(STDOUT_FILENO, buf, len);
            }
        }
    }
    return 0;
}
