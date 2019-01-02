#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C"{
#endif

    void init_apiTest(void** handle);
    void send_apiTest(void* handle, char* sendData, int sendLen);
    void recv_apiTest(void* handle, char* recvData, int* recvLen);
    void clos_apiTest(void* handle);

#ifdef __cplusplus
}
#endif


