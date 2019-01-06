#include <iostream>
#include <string>
using namespace std;

void test()
{
    pair<string, int> p("string", 10);
    cout << p.first << endl;
    cout << p.second << endl;

    pair<string, int> pp = make_pair("Tom", 20);
    cout << pp.first << endl;
    cout << pp.second << endl;
}

int main()
{
    test();
    return 0;
}
