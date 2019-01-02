#include <iostream>

using namespace std;

class MyException
{
public:
    MyException()
    {
        cout << "Default Construct" << endl;
    }

    MyException(const MyException& e)
    {
        cout << "Copy Construct" << endl;
    }

    ~MyException()
    {
        cout << "DeStruct" << endl;
    }
};

void doWork1()
{
    throw MyException();
}

void test1()
{
    try {
        doWork1();
    } catch (MyException e) {
        cout << "Get Exception" << endl;
    }
}

void doWork2()
{
    throw MyException();
}

void test2()
{
    try {
        doWork2();
    } catch (MyException& e) {
        cout << "Get Exception" << endl;
    }
}

void doWork3()
{
    throw new MyException();
}

void test3()
{
    try {
        doWork3();
    } catch (MyException* e) {
        cout << "Get Exception" << endl;
        delete e;
    }
}

int main()
{
    test1();
    cout << "----------------------------------" << endl;
    test2();
    cout << "----------------------------------" << endl;
    test3();
    return 0;
}
