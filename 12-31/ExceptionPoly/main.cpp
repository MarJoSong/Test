#include <iostream>

using namespace std;

class BaseException
{
public:
    virtual void printError()
    {}
};

class NULLpointException:public BaseException
{
public:
    void printError()
    {
        cout << "nullptr" << endl;
    }
};

class OutofArrayException:public BaseException
{
public:
    void printError()
    {
        cout << "Out of Array" << endl;
    }
};

void doWork()
{
    throw OutofArrayException();
}

void test()
{
    try {
        doWork();
    } catch (BaseException& e) {
        e.printError();
    }
}

int main()
{
    test();
    return 0;
}
