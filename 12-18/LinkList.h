#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif

    typedef void* LinkList;
    typedef void(*FOREACH)(void*);

    LinkList Init_LinkList();
    void Insert_LinkList(LinkList list, int pos, void* data);
    void Foreach_LinkList(LinkList list, FOREACH myForeach);
    int Size_LinkList(LinkList list);
    void RemoveByPos_LinkList(LinkList list, int pos);
    void RemoveByValue_LinkList(LinkList list, void* data, int(*compare)(void*, void*));
    void Clean_LinkList(LinkList list);
    void Destory_LinkList(LinkList* list);

#ifdef __cplusplus
}
#endif
