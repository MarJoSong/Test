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
