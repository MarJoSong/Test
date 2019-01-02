#include <stdio.h>
#include <stddef.h>

struct A{
    char a1;
    int b;
};

void test01(){
    struct A a;
    a.a1 = 'A';
    a.b = 20;

    printf("%d\n",*(int*)((char*)&a + offsetof(struct A, b)));
    printf("%d\n", *((int*)&a +1));
}

struct B{
    int m;
    double n;
};

struct C{
    char a;
    int b;
    struct B c;
    /*
     * 等同于
     * char a;
     * int b;
     * int m;
     * double n;
     * 注意其赋值方式
     */
};

void test02(){
    struct C c = {'A', 3, 30, 3.14};
    printf("a=%c\n",*(char*)&c);
    int off1 = offsetof(struct C, c);
    int off2 = offsetof(struct B, n);
    printf("c.c.n=%.2f\n",*(double*)((char*)&c+off1+off2));
    printf("c.c.m=%d\n", (((struct B*)((int*)&c+2)) ->m));
}

int main()
{
    //test01();
    test02();
    return 0;
}
