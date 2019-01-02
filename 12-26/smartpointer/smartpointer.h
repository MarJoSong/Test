#pragma once
#include <iostream>
#include "person.h"

using namespace std;

class smartPointer
{
public:
    smartPointer(Person* preson);
    ~smartPointer();
    Person* operator->();
    Person& operator*();

private:
    Person* person;
};
