#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myapi.h"

typedef void(*init_CSoclerProtocol)(void** handle);
typedef void(*send_CSoclerProtocol)(void* handle, char* sendData, int sendLen);
typedef void(*recv_CSoclerProtocol)(void* handle, char* recvData, int* recvLen);
typedef void(*close_CSoclerProtocol)(void* handle);

void FrameWork(init_CSoclerProtocol init,
               send_CSoclerProtocol send,
               recv_CSoclerProtocol recv,
               close_CSoclerProtocol close)
{
    void* handle = NULL;
    init(&handle);

    char sendBuf[] = "Hello World";
    int sendLen = (int)strlen(sendBuf);
    send(handle, sendBuf, sendLen);

    char recvBuf[] = "Hello World";
    int recvLen;
    recv(handle, recvBuf, &recvLen);

    close(handle);
    handle = NULL;
}

void test()
{
    FrameWork(init_apiTest, send_apiTest, recv_apiTest, clos_apiTest);
}

int main()
{
    test();
    printf("Hello World!\n");
    return 0;
}
