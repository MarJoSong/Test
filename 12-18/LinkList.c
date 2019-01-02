#include "LinkList.h"

struct linkNode
{
    void* data;
    struct linkNode* next;
};

struct LList
{
    struct linkNode header;
    int size;
};

LinkList Init_LinkList()
{
    struct LList* list = (struct LList*)malloc(sizeof (struct LList));
    if(NULL == list)
    {
        return NULL;
    }

    list->header.data = NULL;
    list->header.next = NULL;
    list->size = 0;

    return list;
}

void Insert_LinkList(LinkList list, int pos, void *data)
{
    if(NULL == list)
    {
        return;
    }
    if(NULL == data)
    {
        return;
    }

    struct LList* myList = (struct LList*)list;
    if(pos<0 || pos>myList->size-1)
    {
        pos = myList->size;
    }

    struct linkNode* pCurrent = &(myList->header);
    for (int i=0; i<pos; ++i) {
        pCurrent = pCurrent->next;
    }

    struct linkNode* newNode = (struct linkNode*)malloc(sizeof (struct linkNode));
    newNode->data = data;
    newNode->next = pCurrent->next;
    pCurrent->next = newNode;

    ++(myList->size);
}

void Foreach_LinkList(LinkList list, FOREACH myForeach)
{
    if(NULL == list)
    {
        return;
    }
    if(NULL == myForeach)
    {
        return;
    }

    struct LList* myList = (struct LList*)list;
    struct linkNode* pCurrent = myList->header.next;
    while (NULL != pCurrent)
    {
        myForeach(pCurrent->data);
        pCurrent = pCurrent->next;
    }
}

int Size_LinkList(LinkList list)
{
    if (NULL == list) {
        return 0;
    }
    struct LList* myList = (struct LList*)list;
    return myList->size;
}

void Clean_LinkList(LinkList list)
{
    if(NULL == list)
    {
        return;
    }

    struct LList* myList = (struct LList*)list;
    struct linkNode* pCurrent = myList->header.next;
    while (NULL != pCurrent) {
        struct linkNode* pNext = pCurrent->next;
        free(pCurrent);
        pCurrent = pNext;
    }
    myList->header.next = NULL;
    myList->size = 0;
}

void Destory_LinkList(LinkList* list)
{
    if(NULL == list)
    {
        return;
    }
    if(NULL == *list)
    {
        return;
    }
    Clean_LinkList(*list);
    free(*list);
    *list = NULL;

}

void RemoveByPos_LinkList(LinkList list, int pos)
{
    if(NULL == list)
    {
        return;
    }
    struct LList* myList = (struct LList*)list;
    if(pos<0 || pos>myList->size-1)
    {
        return;
    }

    struct linkNode* pCurrent = &(myList->header);
    for (int i=0; i<pos; ++i) {
        pCurrent = pCurrent->next;
    }
    struct linkNode* pDel = pCurrent->next;

    pCurrent->next = pDel->next;
    free(pDel);
    pDel = NULL;
    --(myList->size);
}



void RemoveByValue_LinkList(LinkList list, void *data, int (*compare)(void *, void *))
{
    if(NULL == list)
    {
        return;
    }
    if(NULL == data)
    {
        return;
    }
    if(NULL == compare)
    {
        return;
    }

    struct LList* myList = (struct LList*)list;
    struct linkNode* pPre = &(myList->header);
    struct linkNode* pCurrent = pPre->next;
//    for (int i=0; i<myList->size; ++i) {
//        if(compare(data, pCurrent->data))
//        {
//            RemoveByPos_LinkList(myList, i);
//            break;
//        }

//        pPre = pCurrent;
//        pCurrent = pCurrent->next;
//    }

    while (NULL != pCurrent) {
        if(compare(data, pCurrent->data))
        {
            pPre->next = pCurrent->next;
            free(pCurrent);
            pCurrent = NULL;
            --(myList->size);
            break;
        }

        pPre = pCurrent;
        pCurrent = pCurrent->next;
    }

}
