#include <iostream>
#include <string>
#include "myarray.hpp"

using namespace std;

void printArray(MyArray<int>& array)
{
    for (int i=0; i<array.getSize(); ++i)
    {
        cout << array[i] << endl;
    }
}

class Person
{
public:
    Person(){}
    explicit Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string getName()
    {
        return this->m_Name;
    }
    int getAge()
    {
        return this->m_Age;
    }

private:
    string m_Name;
    int m_Age;
};

void printArray(MyArray<Person>& array)
{
    for (int i=0; i<array.getSize(); ++i)
    {
        cout << array[i].getName() << "  " << array[i].getAge() << endl;
    }
}

void test()
{
    MyArray<int> test(10);
    for (int i=0; i<test.getCapacity(); ++i)
    {
        test.pushBack(i+100);
    }
    printArray(test);


    MyArray<Person> t1(2);
    Person* p = new Person[4];
    p[0] = Person("t1", 10);
    p[1] = Person("t2", 20);
    p[2] = Person("t3", 30);
    p[3] = Person("t4", 40);

    for (int i=0; i<4; ++i)
    {
        t1.pushBack(p[i]);
    }
    printArray(t1);
}

int main()
{
    test();
    return 0;
}
