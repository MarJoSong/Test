#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <event2/event.h>

//读回调函数
void rdfifo(evutil_socket_t fd, short what, void* arg)
{
    //读管道
    char buf[1024] = {0};
    int len = read(fd, buf, sizeof(buf));
    if(len==-1)
    {
        perror("read error");
        exit(1);
    }
    printf("Data len = %d, buf = %s\n", len, buf);
    printf("read event : %s\n", what&EV_READ ? "Yes":"No");
}

int main()
{   
    //创建管道
    unlink("rwfifo");
    mkfifo("rwfifo", 0664);

    //打开管道，获得文件描述符,非阻塞,持续读，不管有无数据
    int fd = open("rwfifo", O_RDONLY | O_NONBLOCK);
    if(fd==-1)
    {
        perror("error");
        exit(1);
    }

    //创建事件框架
    struct event_base* base;
    base = event_base_new();

    //创建读事件
    struct event* ev;
    ev = event_new(base, fd, EV_READ | EV_PERSIST, rdfifo, NULL);

    //添加读事件到框架
    event_add(ev, NULL);

    //进入事件循环
    event_base_dispatch(base);

    //释放
    event_free(ev);
    event_base_free(base);
    close(fd);

    return 0;
}

