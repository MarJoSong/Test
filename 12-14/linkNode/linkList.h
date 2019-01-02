#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct linkNode{
    int data;
    struct linkNode* next;
};

#ifdef __cplusplus
extern "C"{
#endif

    struct linkNode* initial_linkNode();

    void foreach_linkNode(struct linkNode* header);

    void count_linkNode(struct linkNode* header);

    void InsertByValue_linkNode(struct linkNode*, int oldval, int newval);

    void reverse_linkNode(struct linkNode* header);

    void clear_linkNode(struct linkNode* header);

    void delete_linkNode(struct linkNode* header, int denumber);

    void destory_linkNode(struct linkNode** header);

#ifdef __cplusplus
}
#endif


