#include <iostream>
#include <string>

using namespace std;

class MyException:public exception
{
public:
    MyException();
    MyException(string info)
    {
        this->errorInfo = info;
    }

    virtual ~MyException()
    {}

    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT
    {
        return this->errorInfo.c_str();
    }

private:
    string errorInfo;
};

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        if(age<0 || age>200)
            throw MyException("Age invalid");
        this->m_Age = age;
    }

private:
    string m_Name;
    int m_Age;
};

void test()
{
    try {
        Person p("Tom", 300);
    } catch (MyException& e) {
        cout << e.what() << endl;
    }
}

int main()
{
    test();
    return 0;
}
