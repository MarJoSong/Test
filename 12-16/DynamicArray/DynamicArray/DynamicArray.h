#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

    struct DynamicArray{
        void **addr;
        int capacity;
        int size;
    };

    typedef enum _op_
    {
        operationOnlyOnce = 1,              //Delete once
        operationUntilTargetNotFound = 0    //Delete many times
    }op;

    struct DynamicArray* Init_DynamicArray(int capacity);
    void InsertByPos_DynamicArray(struct DynamicArray * arr, int pos, void* data);
    void Foreach_DynamicArray(struct DynamicArray* arr, void(*__callback)(void*));
    void DeleteByPos_DynamicArray(struct DynamicArray* arr, int pos);
    void DeleteByValue_DynamicArray(struct DynamicArray* arr, void* data, int compare(void *, void *), op _type_);
    void Destory_DynamicArray(struct DynamicArray** arr);

#ifdef __cplusplus
}
#endif
