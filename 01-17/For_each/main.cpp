#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct MyPrint
{
    void operator()(int val)
    {
        cout << val << endl;
        ++count;
    }
    int count = 0;
};

void test01()
{
    vector<int> v;
    for (int i=0; i<10; ++i)
    {
        v.push_back(i);
    }

    MyPrint printer = for_each(v.begin(), v.end(), MyPrint());
    cout << "´òÓ¡´ÎÊý: " << printer.count << endl;
}

class TransForm
{
public:
    int operator()(int val)
    {
        return val + 10;
    }
};

void test02()
{
    vector<int> v;
    for (int i=0; i<10; ++i)
    {
        v.push_back(i);
    }

    vector<int> vTarget;
    vTarget.resize(v.size());

    transform(v.begin(), v.end(), vTarget.begin(), TransForm());
    for_each(vTarget.begin(), vTarget.end(), [](int val){cout << val <<endl;});
}

class TransForm2
{
public:
    int operator()(int val1, int val2)
    {
        return val1 + val2;
    }
};

void test03()
{
    vector<int> v1;
    vector<int> v2;
    for (int i=0; i<10; ++i)
    {
        v1.push_back(i+10);
        v2.push_back(i*100);
    }

    vector<int> vTarget;
    vTarget.resize(v1.size());

    transform(v1.begin(), v1.end(), v2.begin(), vTarget.begin(), TransForm2());
    for_each(vTarget.begin(), vTarget.end(), [](int val){cout << val <<endl;});
}


int main()
{
    //test01();
    //test02();
    test03();
    return 0;
}
