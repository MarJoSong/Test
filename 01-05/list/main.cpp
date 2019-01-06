#include <iostream>
#include <list>

using namespace std;

void test()
{
    list<int> myList;
    for (int i=0; i<10; ++i)
    {
        myList.push_back(i);
    }

    for (list<int>::iterator it=myList.begin(); it!=myList.end(); ++it)
    {
        cout << *it << endl;
    }
}

int main()
{
    test();
    return 0;
}
