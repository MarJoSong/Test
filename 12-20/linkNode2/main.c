#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linknode2.h"

struct Person{
    struct LinkNode node;
    char name[64];
    int age;
};

void myPrint(void* data)
{
    struct Person* person = (struct Person*)data;
    printf("name: %s\tage: %d\n", person->name, person->age);
}

void test()
{
    LinkList list = Init_LinkList();

    struct Person p1 = {{NULL}, "aaa", 10};
    struct Person p2 = {{NULL}, "bbb", 20};
    struct Person p3 = {{NULL}, "ccc", 30};
    struct Person p4 = {{NULL}, "ddd", 40};
    struct Person p5 = {{NULL}, "eee", 50};
    struct Person p6 = {{NULL}, "fff", 60};

    InsertByPos(list, 0, &p1);
    InsertByPos(list, 0, &p2);
    InsertByPos(list, 0, &p3);
    InsertByPos(list, 0, &p4);
    InsertByPos(list, 0, &p5);
    InsertByPos(list, 0, &p6);
    foreach(list, myPrint);

    RemoveByPos(list, 3);
    foreach(list, myPrint);

    Destory_LinkList(&list);
    foreach(list, myPrint);
}

int main()
{
    test();

    return 0;
}
