#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        m_Name = name;
        m_age = age;
    }

    string m_Name;
    int m_age;
};

template <class T>
bool ageCompare(T& a, T&b)
{
    if(a == b)
        return true;
    return false;
}

template<> bool ageCompare<Person>(Person& a, Person&b)
{
    if(a.m_age == b.m_age)
        return true;
    return false;
}

void test()
{
    int a = 5;
    int b = 5;
    int ret = ageCompare(a, b);
    cout << ret << endl;

    Person p1("Tom", 10);
    Person p2("Jerry", 8);
    ret = ageCompare(p1, p2);
    cout << ret << endl;
}

int main()
{
    test();
    return 0;
}
