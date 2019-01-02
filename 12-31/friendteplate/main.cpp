#include <iostream>
#include <string>

using namespace std;

template<class T1, class T2>class Person;

template<class T1, class T2>void showInfo2(Person<T1,T2>& p);

template<class T1, class T2>
class Person
{
    friend void showInfo(Person<T1,T2>& p)
    {
        cout << p.m_Name << endl;
        cout << p.m_Age << endl;
    }
    friend void showInfo2<>(Person<T1,T2>& p);
public:
    Person(T1 name, T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

private:
    T1 m_Name;
    T2 m_Age;
};

template<class T1, class T2>
void showInfo2(Person<T1,T2>& p)
{
    cout << p.m_Name << endl;
    cout << p.m_Age << endl;
}

void test()
{
    Person<string, int> p1("Tom", 10);
    showInfo(p1);
    showInfo2(p1);
}

int main()
{
    test();
    return 0;
}
