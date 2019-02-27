#include <iostream>
#include <set>

using namespace std;

void printSet(set<int>& s)
{
    for (set<int>::iterator it=s.begin(); it!=s.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test()
{
    set<int> t;
    t.insert(1);
    t.insert(7);
    t.insert(3);
    t.insert(9);
    t.insert(5);

    printSet(t);

    if(t.empty())
    {
        cout << "空" << endl;
    }
    else
    {
        cout << "Size = " << t.size() << endl;
    }

    t.erase(t.begin());
    t.erase(7);
    printSet(t);

    set<int>::iterator pos = t.find(5);
    if(pos != t.end())
    {
        cout << "Got! The value is " << *pos << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    unsigned long long num = t.count(5);
    cout << "5的个数为: " << num << endl;

    set<int>::iterator uqpos = t.lower_bound(3);
    if(uqpos != t.end())
    {
        cout << "大于等于3的key为: " << *uqpos << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }

    set<int>::iterator upos = t.upper_bound(3);
    if(upos != t.end())
    {
        cout << "大于3的key为: " << *upos << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }


    pair<set<int>::iterator, set<int>::iterator> ret = t.equal_range(3);
    if(ret.first!=t.end())
    {
        cout << "找到lower_bound的值: " << *(ret.first) << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }

    if(ret.second!=t.end())
    {
        cout << "找到upper_bound的值: " << *(ret.second) << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}

int main()
{
    system("chcp 65001");
    test();

    return 0;
}
