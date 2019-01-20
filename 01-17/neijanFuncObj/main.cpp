#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

void test01()
{
    negate<int> n;
    cout << n(10) << endl;

    plus<int> p;
    cout << p(10,20) << endl;
}

void test02()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    sort(v.begin(), v.end(), greater<int>());

    for_each(v.begin(), v.end(), [](int val){cout << val << " ";});

}

int main()
{
    test02();
    return 0;
}
