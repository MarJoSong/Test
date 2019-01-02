#include <stdio.h>

void print()
{
    printf("Hello World!\n");
}

int myfunc(int a, char b)
{
    printf("myfunc(%d, %c)\n", a, b);
    return 0;
}

void test01()
{
    typedef int(FUN_TYPE)(int, char);
    FUN_TYPE*  pfunc = myfunc;

    pfunc(10, 'a');
    (*pfunc)(20, 'b');
    myfunc(30, 'c');

    typedef int(*pFUN_TYPE)(int, char);
    pFUN_TYPE  func = myfunc;

    func(40, 'd');

    int(*fff)(int, char) = (int(*)(int, char))NULL;
    fff = myfunc;
    fff(50,'e');
    printf("myfunc sizeof = %d\n", sizeof (myfunc));
    printf("fff sizeof = %d\n", sizeof (fff));

}


int main()
{
    printf("print()函数入口地址:%d\n", (int)print);
    int* funcAddr = (int*)4199776;
    void(*func)() = funcAddr;
    func();

    test01();
    printf("int数据类型 sizeof = %d\n", sizeof (int));
    printf("int指针类型 sizeof = %d\n", sizeof (int*));

    return 0;
}
