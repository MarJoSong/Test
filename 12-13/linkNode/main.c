#include <stdio.h>

struct linkNode{
    int data;
    struct linkNode* next;
};

void test01()
{
    struct linkNode node1 = {10, NULL};
    struct linkNode node2 = {20, NULL};
    struct linkNode node3 = {30, NULL};
    struct linkNode node4 = {40, NULL};
    struct linkNode node5 = {50, NULL};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    struct linkNode* pCurrent = &node1;

    while (pCurrent->next != NULL) {
        printf("%d\n", pCurrent->data);
        pCurrent = pCurrent->next;
    }
}

int main()
{
    test01();

    return 0;
}
