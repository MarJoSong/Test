#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>

using namespace std;

void test1()
{
    vector<int> v1;
    vector<int> v2;
    for (int i=0; i<5; ++i)
    {
        v1.push_back(i);
        v2.push_back(i+10);
    }
    vector<int> vTarget;
    vTarget.resize(v1.size()+v2.size());

    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), vTarget.end(), [](int v){cout << v <<" ";});
}

void test12()
{
    vector<int> v1;
    for (int i=0; i<5; ++i)
    {
        v1.push_back(10-i);
    }
    for_each(v1.begin(), v1.end(), [](int v){cout << v <<" ";});
    cout << endl;

    sort(v1.begin(), v1.end());
    for_each(v1.begin(), v1.end(), [](int v){cout << v <<" ";});
    cout << endl;

    sort(v1.begin(), v1.end(), greater<int>());
    for_each(v1.begin(), v1.end(), [](int v){cout << v <<" ";});
}

void test123()
{
    vector<int> v1;
    for (int i=0; i<5; ++i)
    {
        v1.push_back(10-i);
    }
    for_each(v1.begin(), v1.end(), [](int v){cout << v <<" ";});
    cout << endl;

    random_shuffle(v1.begin(), v1.end());
    for_each(v1.begin(), v1.end(), [](int v){cout << v <<" ";});
    cout << endl;
}

void test1234()
{
    vector<int> v1;
    for (int i=0; i<5; ++i)
    {
        v1.push_back(10-i);
    }
    for_each(v1.begin(), v1.end(), [](int v){cout << v <<" ";});
    cout << endl;

    reverse(v1.begin(), v1.end());
    for_each(v1.begin(), v1.end(), [](int v){cout << v <<" ";});
    cout << endl;
}

int main()
{
    srand((unsigned int)time(nullptr));
    test1234();
    return 0;
}
