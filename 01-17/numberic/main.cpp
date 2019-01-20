#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <functional>

using namespace std;

void test1()
{
    vector<int> v;
    for (int i=0; i<100; i++)
    {
        v.push_back(i+1);
    }

    int sum = accumulate(v.begin(), v.end(), 0, minus<int>());
    cout << sum;
    fill(v.begin(), v.end(), 1);
    sum = accumulate(v.begin(), v.end(), 0);
    cout << sum;
}

int main()
{
    test1();
    return 0;
}
