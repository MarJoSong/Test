#include "seqstack.h"


SeqStack Init_SeqStack()
{
    struct SStack* stack = malloc(sizeof (struct SStack));
    if(NULL == stack)
    {
        return NULL;
    }
    memset(stack, 0, sizeof (struct SStack));
    stack->size = 0;

    return stack;
}

void Push_SeqStack(SeqStack stack, void *data)
{
    if(NULL == stack)
    {
        return;
    }
    if(NULL == data)
    {
        return;
    }

    struct SStack* myStack = (struct SStack*)stack;
    myStack->data[myStack->size] = data;
    myStack->size++;
}

void Pop_SeqStack(SeqStack stack)
{
    if(NULL == stack)
    {
        return;
    }
    struct SStack* myStack = (struct SStack*)stack;
    if(0 == myStack->size)
    {
        return;
    }

    myStack->data[myStack->size--] = NULL;
}

void *Top_SeqStack(SeqStack stack)
{
    if(NULL == stack)
    {
        return NULL;
    }
    struct SStack* myStack = (struct SStack*)stack;
    if(0 == myStack->size)
    {
        return NULL;
    }

    return myStack->data[myStack->size-1];
}

int Size_SeqStack(SeqStack stack)
{
    if(NULL == stack)
    {
        return -1;
    }
    struct SStack* myStack = (struct SStack*)stack;
    return myStack->size;
}

void Destory_SeqStack(SeqStack stack)
{
    if(NULL == stack)
    {
        return;
    }
    free(stack);
}
