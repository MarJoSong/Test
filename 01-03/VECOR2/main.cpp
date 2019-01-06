#include <iostream>
#include <vector>

using namespace std;


void test()
{
    vector<int> v;
    for (int i=0; i<100000; ++i)
    {
        v.push_back(i);
    }
    cout << v.capacity() << endl;
    v.resize(3);
    cout << "----------" << endl;
    for (vector<int>::iterator it=v.begin();it!=v.end();++it)
    {
        cout << *it << endl;
    }
    cout << v.capacity() << endl;
    vector<int>(v).swap(v);
    cout << "----------" << endl;
    for (vector<int>::iterator it=v.begin();it!=v.end();++it)
    {
        cout << *it << endl;
    }
    cout << v.capacity() << endl;
}

void test01()
{
    vector<int> v;

    int* p = nullptr;
    int num=0;
    for (int i=0; i<100000; ++i)
    {
        v.push_back(i);
        if(p!=&v[0])
        {
            p = &v[0];
            ++num;
        }
    }
    cout << num << endl;
    cout << "----------" << endl;
    vector<int> vr;
    vr.reserve(100000);

    int* pp = nullptr;
    int nump=0;
    for (int i=0; i<100000; ++i)
    {
        vr.push_back(i);
        if(pp!=&vr[0])
        {
            pp = &vr[0];
            ++nump;
        }
    }
    cout << nump << endl;
}

void test02()
{
    vector<int> v;
    for (int i=0; i<10; ++i)
    {
        v.push_back(i);
    }
    for (vector<int>::reverse_iterator it = v.rbegin(); it!=v.rend(); ++it)
    {
        cout << *it << endl;
    }
}

int main()
{
    //test01();
    test02();
    return 0;
}
