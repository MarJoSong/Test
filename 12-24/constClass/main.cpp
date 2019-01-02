#include <iostream>

using namespace std;

class Person
{
public:
    Person(int a):a(a){}
    void show() const
    {
        //a = 10;
        b = 20;
        c = 30;
        cout << "b=" << b << endl;
        cout << "c=" << c << endl;
    }

private:
    int a;
    mutable int b;
    static int c;
};
int Person::c = 15;

int main()
{
    Person p1(10);
    p1.show();

    const Person p2(11);
    p2.show();
    return 0;
}
