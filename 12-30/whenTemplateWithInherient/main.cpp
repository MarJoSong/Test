#include <iostream>

using namespace std;

template <class T>
class Base
{
public:
    T m_A;
};

class Son:public Base<int>
{
public:
    int m_B;
};

template<class T1, class T2>
class Son2:public Base<T2>
{
public:
    Son2()
    {
        cout << typeid (T1).name() << typeid (T2).name() << endl;
    }
    T1 m_C;
};

void test()
{
    Base<double>* father = new Son2<int, double>;
}

int main()
{
    test();
    return 0;
}
