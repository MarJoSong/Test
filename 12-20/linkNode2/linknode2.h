#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C"{
#endif

//链表节点数据结构
struct LinkNode{
    struct LinkNode* next;
};

//链表结构体
struct LList{
    struct LinkNode header;
    int size;
};

typedef void* LinkList;

//初始化链表
LinkList Init_LinkList();

//按位置插入数据
void InsertByPos(LinkList list, int pos, void* data);

//便利链表
void foreach (LinkList list, void(*foreach)(void*));

//按位置删除数据
void RemoveByPos(LinkList list, int pos);

//销毁节点
void Destory_LinkList(LinkList* list);

#ifdef __cplusplus
}
#endif
