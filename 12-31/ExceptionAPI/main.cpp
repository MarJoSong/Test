#include <iostream>

using namespace std;

void fun() throw(int, double, char)
{
    throw -1;
}


int main()
{
    try {
        fun();
    } catch (int) {
        cout << "Get Exception" << endl;
    }
    return 0;
}
