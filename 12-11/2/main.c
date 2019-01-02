#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#pragma pack(show)
struct A{
    char a;
    int b;
};


void test01(){
    char a=39;
    char x = 38;
    int b = 6;
    int c = 7;
    double d = 8;
    double e = 9;

    printf("%p\t=\t%x\n", (void*)&a,a);
    printf("%p\t=\t%x\n", (void*)&x,x);
    printf("%p\t=\t%x\n", (void*)&b,b);
    printf("%p\t=\t%x\n", (void*)&c,c);
    printf("%p\t=\t%x\n", (void*)&d,d);
    printf("%p\t=\t%x\n", (void*)&e,e);
    system("pause");
}


int main()
{
    test01();
    printf("Hello World!\n");
    return 0;
}
