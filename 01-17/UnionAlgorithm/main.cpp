#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void test1()
{
    vector<int> v1;
    vector<int> v2;
    for (int i=0; i<10; ++i)
    {
        v1.push_back(i);
        v2.push_back(i+5);
    }
    vector<int> vT;
    vT.resize(min(v1.size(), v2.size()));

    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vT.begin());
    copy(vT.begin(), itEnd, ostream_iterator<int>(cout, " "));
}

void test12()
{
    vector<int> v1;
    vector<int> v2;
    for (int i=0; i<10; ++i)
    {
        v1.push_back(i);
        v2.push_back(i+5);
    }
    vector<int> vT;
    vT.resize(v1.size() + v2.size());

    vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vT.begin());
    copy(vT.begin(), itEnd, ostream_iterator<int>(cout, " "));
}

void test123()
{
    vector<int> v1;
    vector<int> v2;
    for (int i=0; i<10; ++i)
    {
        v1.push_back(i);
        v2.push_back(i+5);
    }
    vector<int> vT;
    vT.resize(max(v1.size(), v2.size()));

    vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vT.begin());
    copy(vT.begin(), itEnd, ostream_iterator<int>(cout, " "));
    cout << endl;

    itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vT.begin());
    copy(vT.begin(), itEnd, ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    test123();
    return 0;
}
