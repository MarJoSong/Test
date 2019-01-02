#include "myapi.h"

struct Info
{
    char data[1024];
    int len;
};

void init_apiTest(void** handle)
{
    if(nullptr == handle)
        return;

    struct Info* info = (struct Info*)malloc(sizeof (struct Info));
    memset(info, 0, sizeof (struct Info));
    *handle = info;
}

void send_apiTest(void* handle, char* sendData, int sendLen)
{
    if(nullptr == handle)
        return;
    if(nullptr == sendData)
        return;
    if(NULL == sendLen)
        return;

    struct Info* info = (struct Info*)handle;
    strncpy(info->data, sendData, (size_t)sendLen);
    info->len = sendLen;
}

void recv_apiTest(void* handle, char* recvData, int* recvLen)
{
    if(nullptr == handle)
        return;
    if(nullptr == recvData)
        return;
    if(nullptr == recvLen)
        return;

    struct Info* info = (struct Info*)handle;
    strncpy(recvData,info->data, (size_t)info->len);
    *recvLen = info->len;
}

void clos_apiTest(void* handle)
{
    if(nullptr == handle)
        return;
    free(handle);
}
