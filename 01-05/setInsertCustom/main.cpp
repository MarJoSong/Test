#include <iostream>
#include <string>
#include <set>

using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

class myComparePerson
{
public:
    bool operator()(const Person& p1, const Person& p2)
    {
        return p1.m_Age < p2.m_Age;
    }
};

void printPerson(set<Person, myComparePerson>& p)
{
    for (set<Person, myComparePerson>::iterator it=p.begin(); it!=p.end(); ++it)
    {
        cout << "姓名: " << it->m_Name << "年龄: " << it->m_Age << endl;
    }
}

void test()
{
    set<Person, myComparePerson> p;
    p.insert(Person("大娃", 10));
    p.insert(Person("三娃", 8));
    p.insert(Person("五娃", 7));
    p.insert(Person("七娃", 5));

    printPerson(p);
}

int main()
{
    system("chcp 65001");
    test();
    return 0;
}
