#include "linkList.h"

void test01()
{
    struct linkNode* header = initial_linkNode();

    printf("第一遍遍历\n");
    foreach_linkNode(header);
    count_linkNode(header);

    printf("逆序遍历\n");
    reverse_linkNode(header);
    foreach_linkNode(header);
    count_linkNode(header);

    InsertByValue_linkNode(header, 44, 33);

    printf("第二遍遍历\n");
    foreach_linkNode(header);
    count_linkNode(header);

    clear_linkNode(header);
    InsertByValue_linkNode(header, 00, 11);
//    InsertByValue_linkNode(header, 22, 33);
//    InsertByValue_linkNode(header, 44, 55);
//    InsertByValue_linkNode(header, 66, 77);
    printf("第三遍遍历\n");
    foreach_linkNode(header);
    count_linkNode(header);

    delete_linkNode(header, 11);
    printf("第四遍遍历\n");
    foreach_linkNode(header);
    count_linkNode(header);

    destory_linkNode(&header);
    foreach_linkNode(header);
    count_linkNode(header);
}

int main()
{
    test01();

    return 0;
}
