#include <iostream>
#include <string>
#include "person.cpp"

using namespace std;

void test()
{
    Person<string, int> p("hua", 24);
    p.showInfo();
}

int main()
{
    test();
    return 0;
}
