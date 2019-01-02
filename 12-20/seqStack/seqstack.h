#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif

#define MAX 1024

struct SStack{
    void* data[MAX];
    int size;
};

typedef void* SeqStack;

SeqStack Init_SeqStack();

void Push_SeqStack(SeqStack stack, void* data);

void Pop_SeqStack(SeqStack stack);

void* Top_SeqStack(SeqStack stack);

int Size_SeqStack(SeqStack stack);

void Destory_SeqStack(SeqStack stack);

#ifdef __cplusplus
}
#endif
