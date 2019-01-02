#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        if(age<0 || age>200)
        {
            throw out_of_range("out of range");
        }
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

void doWork()
{
    Person("Tom", 201);
}

void test()
{
    try {
        doWork();
    } catch (out_of_range e) {
        cout << e.what() << endl;
    }
}
int main()
{
    test();
    return 0;
}
