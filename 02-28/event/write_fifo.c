#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <event2/event.h>

//写回调函数
void wrfifo(evutil_socket_t fd, short what, void* arg)
{
    //写管道
    char buf[1024] = {0};
    static int num = 0;
    sprintf(buf, "hello, world == %d", num++);
    write(fd, buf, strlen(buf)+1);
}

int main()
{   
    //打开管道，获得文件描述符
    int fd = open("rwfifo", O_WRONLY | O_NONBLOCK);
    if(fd==-1)
    {
        perror("error");
        exit(1);
    }

    //创建写事件框架
    struct event_base* base;
    base = event_base_new();

    //创建写事件
    struct event* ev;
    //EV_WRITE检测写缓冲区是否可写,EV_PERSIST持续写,否则只写一次
    ev = event_new(base, fd, EV_WRITE | EV_PERSIST, wrfifo, NULL);

    //添加事件到框架
    event_add(ev, NULL);

    //进入事件循环
    event_base_dispatch(base);

    //释放
    event_free(ev);
    event_base_free(base);
    close(fd);

    return 0;
}

