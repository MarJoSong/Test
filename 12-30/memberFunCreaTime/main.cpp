#include <iostream>

using namespace std;

template<class T>
class Fun
{
public:
    T obj;
    void fun1()
    {
        obj.show1();
    }
    void fun2()
    {
        obj.show2();
    }
};


class Person1
{
public:
    void show1(){}
};

class Person2
{
public:
    void show2(){}
};

void test()
{
    Fun<Person1> f1;
    f1.fun1();
    //f1.fun2();
}

int main()
{
    test();
    cout << "Hello World!" << endl;
    return 0;
}
