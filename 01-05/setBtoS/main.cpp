#include <iostream>
#include <set>

using namespace std;

class myCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void printSet(set<int, myCompare>& s)
{
    for (set<int, myCompare>::iterator it=s.begin(); it!=s.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test()
{
    set<int, myCompare> t;
    t.insert(1);
    t.insert(7);
    t.insert(3);
    t.insert(9);
    t.insert(5);

    printSet(t);
}

int main()
{
    test();
    return 0;
}
