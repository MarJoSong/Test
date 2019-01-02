#include<iostream>
using namespace std;

class Person
{
    friend ostream& operator<<(ostream& cout, Person& p);

public:
    Person()
    {
        m_Num = 0;
    }

    //前置++重载
    Person& operator++()
    {
        this->m_Num++;
        return *this;
    }

    //后置++ 重载
    Person operator++(int)
    {
        //先保存目前数据
        Person tmp = *this;
        m_Num++;
        return tmp;
    }
    int m_Num;
};

ostream& operator<<(ostream& cout, Person& p)
{
    cout << p.m_Num;
    return cout;
}

void test01()
{
    Person p;

    cout << ++(++p) << endl;
    cout << p << endl;
}

int main() {

    test01();

    system("pause");
    return EXIT_SUCCESS;
}
