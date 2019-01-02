#include <iostream>
#include <string>

using namespace std;

template <class T1, class T2>
class Person
{
public:
    Person(T1 name = "Tom", T2 age = 10);
    void showInfo();

    T1 m_Name;
    T2 m_Age;
};

template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    m_Name = name;
    m_Age = age;
}

template <class T1, class T2>
void Person<T1, T2>::showInfo()
{
    cout << "ÐÕÃû: " << m_Name << "\tÄêÁä: " << m_Age << endl;
}

void test()
{
    Person<string, int> p1("Jack", 22);
    p1.showInfo();
}

int main()
{
    test();
    return 0;
}

