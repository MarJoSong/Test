#include <stdio.h>
#include "seqstack.h"

struct Person{
    char name[64];
    int age;
};

void test()
{
    SeqStack stack = Init_SeqStack();

    struct Person p1 = {"aaa", 10};
    struct Person p2 = {"bbb", 20};
    struct Person p3 = {"ccc", 30};
    struct Person p4 = {"ddd", 40};
    struct Person p5 = {"eee", 50};
    struct Person p6 = {"fff", 60};

    Push_SeqStack(stack, &p1);
    Push_SeqStack(stack, &p2);
    Push_SeqStack(stack, &p3);
    Push_SeqStack(stack, &p4);
    Push_SeqStack(stack, &p5);
    Push_SeqStack(stack, &p6);

    while (Size_SeqStack(stack)>0) {
        struct Person* person = (struct Person*)Top_SeqStack(stack);
        printf("Name: %s\tAge: %d\n", person->name, person->age);
        Pop_SeqStack(stack);
    }

    printf("Size: %d", Size_SeqStack(stack));

    Destory_SeqStack(stack);
    stack = NULL;
}


int main()
{
    test();

    return 0;
}
