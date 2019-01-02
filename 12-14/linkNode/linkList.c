#include "linkList.h"

struct linkNode *initial_linkNode()
{
    //为头节点分配内存空间，默认指向空
    struct linkNode* header = malloc(sizeof (struct linkNode));
    header->data = 0;
    header->next = NULL;

    //建立尾节点，默认等于头节点
    struct linkNode* pRear = header;
    int val = -1;

    //输入数据
    while (true) {
        printf("请输入第%d个数据: ", ++header->data);
        scanf("%d", &val);
        if(-1 == val)
        {
            --header->data;
            break;
        }
        //建立新节点，分配内存，数据赋值，指向空
        struct linkNode* newNode = malloc(sizeof (struct linkNode));
        newNode->data = val;
        newNode->next = NULL;

        //原先尾指针指向新节点
        pRear->next = newNode;

        //尾指针调整到新节点
        pRear = newNode;
    }
    return header;
}

void foreach_linkNode(struct linkNode* header)
{
    if(NULL == header)
    {
        printf("链表未初始化\n");
        return;
    }

    struct linkNode* pCurrent = header->next;

    while(NULL !=pCurrent)
    {
        printf("%d\t", pCurrent->data);
        pCurrent = pCurrent->next;
    }
    printf("\n");
}


void InsertByValue_linkNode(struct linkNode* header, int oldval, int newval)
{
    if(NULL == header)
        return;

    //建立前驱和后继辅助节点
    struct linkNode* pPre = header;
    struct linkNode* pNext = pPre->next;

    //判断oldval存在性
    while (NULL != pNext) {
        if(oldval == pNext->data)
            break;
        pPre = pPre->next;
        pNext = pPre->next;
    }

#if 0
    if(NULL == pNext)
        return;
#endif

    //建立插入节点，赋值
    struct linkNode* pInsert = malloc(sizeof (struct linkNode));
    pInsert->data = newval;

    //前驱节点指向插入节点，插入节点指向后继节点
    pPre->next = pInsert;
    pInsert->next = pNext;
    header->data++;
}


void clear_linkNode(struct linkNode* header)
{
    if(NULL == header)
    {
        printf("链表未初始化\n");
        return;
    }

    //建立辅助节点，头节点指向当前辅助节点
    struct linkNode* pCurrent = header->next;

    //判断当前节点是否为空
    while (NULL != pCurrent) {
        //建立辅助NEXT节点，指向当前节点的下一个节点
        struct linkNode* pNext = pCurrent->next;
        //释放当前节点，调整当前节点到NEXT节点
        free(pCurrent);
        pCurrent = pNext;
    }
    //头节点指向空
    header->next = NULL;
    header->data = 0;
}

void delete_linkNode(struct linkNode* header, int denumber)
{
    if(NULL == header)
    {
        printf("链表未初始化\n");
        return;
    }


    //建立前驱和后继辅助节点
    struct linkNode* pPre = header;
    struct linkNode* pNext = pPre->next;

    //匹配后继节点的值，等于denumber跳出
    while (NULL != pNext) {
        if(denumber == pNext->data)
            break;
        pPre = pNext;
        pNext = pPre->next;
    }
    if(NULL == pNext)
        return;
    //前驱节点指向后继节点指向的节点，之后释放后继节点，置空
    pPre->next = pNext->next;
    free(pNext);
    pNext = NULL;
    --header->data;
}

void destory_linkNode(struct linkNode** header)
{
    if(NULL == header)
    {
        printf("链表未初始化\n");
        return;
    }
    //建立辅助节点等于头节点
    struct linkNode* pCurrent = *header;
    //释放其它节点
    while (NULL != pCurrent) {
        struct linkNode* pNext = pCurrent->next;
        free(pCurrent);
        pCurrent = pNext;
    }
    //头节点置空
    *header = NULL;
    printf("链表被销毁\n");
}

void count_linkNode(struct linkNode *header)
{
    if(NULL == header)
    {
        printf("链表未初始化\n");
        return;
    }
    printf("当前链表元素个数为%d\n",header->data);
}

void reverse_linkNode(struct linkNode* header)
{
    if(NULL == header)
    {
        printf("链表未初始化\n");
        return;
    }

    struct linkNode* pPre = NULL;
    struct linkNode* pNext = NULL;
    struct linkNode* pCurrent = header->next;

    while (NULL != pCurrent) {
        pNext = pCurrent->next;
        pCurrent->next = pPre;

        pPre = pCurrent;
        pCurrent = pNext;
    }
    header->next = pPre;
}
