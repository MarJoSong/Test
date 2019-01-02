#include <iostream>
using namespace std;

class abstractCalculator
{
public:
    virtual int getResult(int a, int b)
    {
        return 0;
    }
};

class addCalculator:public abstractCalculator
{
public:
    virtual int getResult(int a, int b)
    {
        return a+b;
    }
};

class subCalculator:public abstractCalculator
{
public:
    virtual int getResult(int a, int b)
    {
        return a-b;
    }
};

class mulCalculator:public abstractCalculator
{
public:
    virtual int getResult(int a, int b)
    {
        return a*b;
    }
};

class divCalculator:public abstractCalculator
{
public:
    virtual int getResult(int a, int b)
    {
        return a/b;
    }
};

void test()
{
    abstractCalculator* abc = new addCalculator;
    cout << abc->getResult(10,10) << endl;
    delete abc;
    abc = new subCalculator;
    cout << abc->getResult(20,50) << endl;
    delete abc;
    abc = new mulCalculator;
    cout << abc->getResult(20,50) << endl;
    delete abc;
    abc = new divCalculator;
    cout << abc->getResult(20,10) << endl;
    delete abc;
    abc = nullptr;
}

int main()
{
    cout << "Hello World!" << endl;
    test();
    return 0;
}
