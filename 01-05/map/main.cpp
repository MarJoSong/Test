#include <iostream>
#include <map>

using namespace std;

void test()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2,20));
    m.insert(map<int, int>::value_type(3, 30));
    m[4] = 40;
    m[5];

    for (map<int, int>::iterator it=m.begin(); it!=m.end(); ++it)
    {
        cout << "Key=" << it->first << " value=" << it->second << endl;
    }
    cout << "---------------" << endl;

    m.erase(5);
    for (map<int, int>::iterator it=m.begin(); it!=m.end(); ++it)
    {
        cout << "Key=" << it->first << " value=" << it->second << endl;
    }
    cout << "---------------" << endl;

    map<int, int>::iterator pos = m.find(3);
    if(pos!=m.end())
    {
        cout << "找到了, Key=" << pos->first << " value=" << pos->second << endl;
    }
    else
    {
        cout << "Sorry" << endl;
    }

    map<int ,int>::iterator ret = m.lower_bound(3);
    if(ret!=m.end())
    {
        cout << "lower Key=" << ret->first << " Value=" << ret->second << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    ret = m.upper_bound(3);
    if(ret!=m.end())
    {
        cout << "Upper Key=" << ret->first << " Value=" << ret->second << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    pair<map<int, int>::iterator, map<int, int>::iterator> dret = m.equal_range(3);
    if(dret.first!=m.end())
    {
        cout << "lower Key=" << dret.first->first << " Value=" << dret.first->second << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
    if(dret.second!=m.end())
    {
        cout << "Upper Key=" << dret.second->first << " Value=" << dret.second->second << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }


    unsigned long long num = m.count(4);
    cout << num << endl;

    if(m.empty())
    {
        cout << "NULL" << endl;
    }
    else
    {
        cout << "size=" << m.size() << endl;
        m.clear();
        cout << "size=" << m.size() << endl;
    }
}

class myCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void test2()
{
    map<int, int, myCompare> s;
    s.insert(pair<int, int>(1, 10));
    s.insert(make_pair(2,20));
    s.insert(map<int, int>::value_type(3, 30));
    s[4] = 40;
    s[5];

    for (map<int, int, myCompare>::iterator it=s.begin(); it!=s.end(); ++it)
    {
        cout << "Key=" << it->first << " value=" << it->second << endl;
    }
}

int main()
{
    system("chcp 65001");

    //test();
    test2();
    return 0;
}
