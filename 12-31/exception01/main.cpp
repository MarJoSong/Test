#include <iostream>

using namespace std;

class MyException
{
public:
    void printError()
    {
        cout << "Custom Exception was catched" << endl;
    }
};

int myDivide(int a, int b)
{
    if(0 == b)
    {
        //throw -1;
        //throw 3.16;
        //throw 'c';
        throw MyException();
    }
    return a/b;
}

void test()
{
    try
    {
        myDivide(10, 0);
    }
    catch (int)
    {
        cout << "Get int Exception" << endl;
    }
    catch (double)
    {
        throw -1;
        cout << "Get double Exception" << endl;
    }
    catch (MyException e)
    {
        e.printError();
    }
    catch (...)
    {
        cout << "Get char Exception" << endl;
    }
}

int main()
{
    try
    {
        test();
    }
    catch (int)
    {
        cout << "Get int Exception" << endl;
    }
    return 0;
}

