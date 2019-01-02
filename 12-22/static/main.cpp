#include <iostream>

using namespace std;

int& doWork2()
{
    static int a = 10;
    return a;
}
void test05()
{

    int &ret = doWork2();

    //如果函数的返回值是引用，那么这个函数调用可以作为左值

    doWork2() = 1000; //相当于写了 a = 1000;

    cout << ret <<endl;

}


void test01()
{
    //int &ref = 10;//引用了不合法的内存，不可以
    const int &ref = 10; //加入const后 ，编译器处理方式为： int tmp = 10; const int &ref = tmp;

    //ref = 10;

    int * p = (int*)&ref;
    *p = 1000;

    cout << "ref = " << ref << endl;

}

const int constA = 10;
int main()
{
    int* p = (int*)&constA;
    *p = 200;
    printf("constA = %d, *p = %d", constA, *p);
}


int main1()
{
    test01();
    return 0;
}
