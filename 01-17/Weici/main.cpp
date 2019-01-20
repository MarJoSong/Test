#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class GreatThat20
{
public:
    bool operator()(int val)
    {
        return val > 20;
    }
};

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void test()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    //放的是函数对象，可以是匿名函数GreatThat20()
    GreatThat20 g;
    vector<int>::iterator pos = find_if(v.begin(), v.end(), g);
    cout << *pos << endl;

    sort(v.begin(), v.end(), MyCompare());
    for_each(v.begin(), v.end(), [](int val){
        cout << val << endl;
    });
}

int main()
{
    test();
    return 0;
}
