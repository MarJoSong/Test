#include <iostream>
#include "smartpointer.h"

using namespace std;

void test()
{
    smartPointer sp(new Person(10));
    cout << sp->showAge() << endl;
    cout << (*sp).showAge() << endl;
}

int main()
{
    test();
    return 0;
}
