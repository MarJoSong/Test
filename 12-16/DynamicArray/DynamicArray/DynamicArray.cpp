#include "DynamicArray.h"


struct DynamicArray* Init_DynamicArray(int capacity);
void InsertByPos_DynamicArray(struct DynamicArray * arr, int pos, void* data);
void Foreach_DynamicArray(struct DynamicArray* arr, void(*__callback)(void*));

struct DynamicArray* Init_DynamicArray(int capacity)
{
    if(capacity <= 0)
        return nullptr;
    struct DynamicArray* arr =  static_cast<struct DynamicArray*>(malloc(sizeof (struct DynamicArray)));
    if(nullptr == arr)
        return nullptr;
    arr->capacity = capacity;
    arr->addr = static_cast<void**>(malloc(sizeof (void*)* static_cast<unsigned long long>(arr->capacity)));
    arr->size = 0;
    return arr;
}

void InsertByPos_DynamicArray(struct DynamicArray * arr, int pos, void* data)
{
    if(nullptr == arr)
        return;
    if(nullptr == data)
        return;
    if(pos<0 || pos>arr->size)
        pos = arr->size;

    if(arr->size >= arr->capacity)
    {
        //申请新内存空间
        int newCapacity = arr->capacity*2;
        void** newAddr = static_cast<void**>(malloc(sizeof (void*) * static_cast<unsigned long long>(newCapacity)));

        memcpy(newAddr, arr->addr, sizeof (void*) * static_cast<unsigned long long>(arr->capacity));//复制地址
//        for (int i=0;i<arr->capacity;++i) {
//            printf("%d\n",(int*)(arr->addr)++);
//        }
        //free(arr->addr);//释放原先空间
        arr->addr = newAddr;
        arr->capacity = newCapacity;
    }

    for (int i=arr->size; i>=pos; --i) {
        arr->addr[i+1] = arr->addr[i];
    }
    arr->addr[pos] = data;
    ++(arr->size);
}

void Foreach_DynamicArray(struct DynamicArray* arr, void(*__callback)(void*))
{
    if(nullptr == arr)
        return;
    if(nullptr == __callback)
        return;
    for (int i=0; i<arr->size; ++i) {
        __callback(arr->addr[i]);
    }
}

void DeleteByPos_DynamicArray(DynamicArray *arr, int pos)
{
    if(nullptr == arr)
        return;
    if(pos <0 || pos >= arr->size)
        return;
    for (int i=pos; i<arr->size-1; ++i) {
        arr->addr[i] = arr->addr[i+1];
    }
    --(arr->size);
}



void DeleteByValue_DynamicArray(DynamicArray *arr, void *data, int compare(void *, void *), op _type_)
{
    if(nullptr == arr)
        return;
    if(nullptr == data)
        return;
    if(nullptr == compare)
        return;
    for (int i=0; i<arr->size; ++i) {
        if(compare(arr->addr[i], data))
        {
            DeleteByPos_DynamicArray(arr, i);
            if(_type_)
                break;
            --i;
        }
    }
}

void Destory_DynamicArray(DynamicArray* arr)
{
    if(nullptr == arr)
        return;
    if(nullptr != arr->addr)
    {
        free(arr->addr);
        arr->addr = nullptr;
    }
    free(arr);
    arr = nullptr;
}
