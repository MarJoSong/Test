#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "LinkList.h"

struct Person{
    char name[64];
    int age;
};

void myPrint(void* data)
{
    struct Person *person = (struct Person*)(data);
    printf("Name:%s\tAge:%d\n", person->name, person->age);
}

int myCompare(void* d1, void* d2)
{
    struct Person* p1 = (struct Person*)d1;
    struct Person* p2 = (struct Person*)d2;
    //字符比较可以用==，字符串要用strcmp，相等返回0
#if 1
    if(strcmp(p1->name, p2->name)==0 && p1->age==p2->age)
    {
        return 1;
    }
    return 0;
#endif
#if 0
    return strcmp(p1->name, p2->name) && p1->age==p2->age;
#endif
}

void test()
{
    LinkList list = Init_LinkList();

    struct Person p1 = {"aaa", 10};
    struct Person p2 = {"bbb", 20};
    struct Person p3 = {"ccc", 30};
    struct Person p4 = {"ddd", 40};
    struct Person p5 = {"eee", 50};
    struct Person p6 = {"fff", 60};
    struct Person p7 = {"ggg", 70};

    Insert_LinkList(list, 0, &p1);  //1
    Insert_LinkList(list, 0, &p2);  //2 1
    Insert_LinkList(list, 1, &p3);  //2 3 1
    Insert_LinkList(list, 2, &p4);  //2 3 4 1
    Insert_LinkList(list, 20, &p5); //2 3 4 1 5
    Insert_LinkList(list, 3, &p6);  //2 3 4 6 1 5
    Insert_LinkList(list, 6, &p7);  //2 3 4 6 1 5 7

    Foreach_LinkList(list, myPrint);
    printf("----------------------------\n");
    printf("linklist size: %d\n", Size_LinkList(list));

    printf("----------------------------\n");
    RemoveByPos_LinkList(list, 3);
    Foreach_LinkList(list, myPrint);
    printf("----------------------------\n");
    printf("linklist size: %d\n", Size_LinkList(list));

    printf("----------------------------\n");
    struct Person pDelPerson = {"bbb", 20};
    RemoveByValue_LinkList(list, &pDelPerson, myCompare);
    Foreach_LinkList(list, myPrint);
    printf("----------------------------\n");
    printf("linklist size: %d\n", Size_LinkList(list));

    printf("----------------------------\n");
    Clean_LinkList(list);
    Foreach_LinkList(list, myPrint);
    printf("----------------------------\n");
    printf("linklist size: %d\n", Size_LinkList(list));

    printf("----------------------------\n");
    Destory_LinkList(list);
    Foreach_LinkList(list, myPrint);
    printf("----------------------------\n");
    printf("linklist size: %d\n", Size_LinkList(list));


}

int main()
{
    test();

    return 0;
}
