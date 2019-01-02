#include <iostream>
#include <string>

using namespace std;

template <class typeName, class typeAge>
class Person
{
public:
    Person(typeName name = "Tom", typeAge age = 10)
    {
        m_Name = name;
        m_Age = age;
    }
    void showInfo()
    {
        cout << "ÐÕÃû: " << m_Name << "\tÄêÁä: " << m_Age << endl;
    }

    typeName m_Name;
    typeAge m_Age;
};

void doWork(Person<string, int>& p)
{
    cout << typeid (p).name() << endl;
    p.showInfo();
}

void t1()
{
    Person<string, int> p1;
    cout << typeid (p1).name() << endl;
    doWork(p1);
}

template<class T1, class T2>
void doWork(Person<T1, T2>& p2)
{
    cout << typeid (p2).name() << endl;
    p2.showInfo();
}

void t2()
{
    Person<string, int> p1;
    doWork(p1);
}

template<class T>
void doWork(T& p)
{
    p.showInfo();
}

void t3()
{
    Person<string, int> p1;
    doWork(p1);
}

int main()
{
    t1();
    t2();
    t3();
    return 0;
}
