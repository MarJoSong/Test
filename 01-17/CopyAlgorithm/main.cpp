#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void test1()
{
    vector<int> v;
    vector<int> vt;
    for (int i=0; i<10; ++i)
    {
        v.push_back(i);
    }

    vt.resize(10);
    copy(v.begin(), v.end(), vt.begin());
    //for_each(vt.begin(), vt.end(), [](int val){cout << val << " ";});

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}

void test12()
{
    vector<int> v;
    for (int i=0; i<10; ++i)
    {
        v.push_back(i);
    }

    replace(v.begin(), v.end(), 3, 300);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

    cout << endl;
    replace_if(v.begin(), v.end(),bind2nd(greater<int>(), 3), 3000);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}

void test123()
{
    vector<int> v;
    for (int i=0; i<10; ++i)
    {
        v.push_back(i);
    }

    vector<int> s;
    s.push_back(10);
    s.push_back(20);
    s.push_back(30);
    s.push_back(40);

    swap(v,s);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
}

int main()
{
    test123();
    return 0;
}
