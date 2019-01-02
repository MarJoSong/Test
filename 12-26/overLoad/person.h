#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person
{
    friend ostream& operator<<(ostream &os, Person& p);
public:
    Person():age(10){}
    Person(int a)
    {
        this->age = a;
    }

    Person operator+(Person& p)
    {
        Person tmp;
        tmp.age = this->age + p.age;
        return tmp;
    }

    Person operator++(int)
    {
        Person tmp = *this;
        this->age++;
        return tmp;
    }

    Person& operator++()
    {
        this->age++;
        return *this;
    }

private:
    int age;
};

ostream& operator<<(ostream &os, Person &p)
{
    os << p.age;
    return os;
}
