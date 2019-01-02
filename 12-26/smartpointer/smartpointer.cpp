#include "smartpointer.h"

smartPointer::smartPointer(Person *preson)
{
    this->person = preson;
}

smartPointer::~smartPointer()
{
    cout << "Îö¹¹º¯Êý" << endl;
    if(nullptr == this->person)
        return;
    free(this->person);
    this->person = nullptr;
}

Person *smartPointer::operator->()
{
    return this->person;
}

Person &smartPointer::operator*()
{
    return *this->person;
}
