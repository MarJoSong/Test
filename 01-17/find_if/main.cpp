#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Person
{
    friend ostream& operator<<(ostream&,Person&);
public:
    Person(string name, int age)
    {
        m_name = name;
        m_age = age;
    }
    bool operator==(const Person& p)
    {
        if(this->m_name == p.m_name && this->m_age == p.m_age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string m_name;
    int m_age;
};

ostream& operator<<(ostream& os,Person& p)
{
    return os << p.m_name << "\t" << p.m_age << endl;
}

void test()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    vector<int>::iterator pos = find(v.begin(), v.end(), 3);
    cout << *pos << endl;

    vector<Person> vp;
    vp.push_back(Person("aaa",111));
    vp.push_back(Person("bbb",123));
    vp.push_back(Person("ccc",132));
    vp.push_back(Person("ddd",1154));
    vector<Person>::iterator posp = find(vp.begin(), vp.end(), Person("bbb", 123));
    if(posp!=vp.end())
    {
        cout << *posp;
    }
    else
    {
        cout << "Î´ÕÒµ½";
    }
}

class PersonCompare :public binary_function<Person*, Person*, bool>
{
public:
    bool operator()(Person* p, Person* c) const
    {
        if(p->m_name == c->m_name && p->m_age == c->m_age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

void test01()
{
    vector<Person*> vpp;
    vpp.push_back(new Person("aaa",111));
    vpp.push_back(new Person("bbb",123));
    vpp.push_back(new Person("ccc",132));
    vpp.push_back(new Person("ddd",1154));
    vector<Person*>::iterator pospp = find_if(vpp.begin(), vpp.end(), bind2nd(PersonCompare(), new Person("bbb",12)));
    if(pospp!=vpp.end())
    {
        cout << *(*pospp);
    }
    else
    {
        cout << "Î´ÕÒµ½";
    }

}

void test012()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(4);
    vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
    if(pos!=v.end())
    {
        cout << *pos;
    }
    else
    {
        cout << "Î´ÕÒµ½";
    }

}

void test0123()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    bool pos = binary_search(v.begin(), v.end(), 4);
    if(pos)
    {
        cout << "ÕÒµ½";
    }
    else
    {
        cout << "Î´ÕÒµ½";
    }

}

void test01234()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    long long num = count(v.begin(), v.end(), 4);
    cout << num;

}

class GreatThanFour
{
public:
    bool operator()(int val)
    {
        return val >=4;
    }
};

void test012345()
{
    vector<int> v;
    for (int i=0; i<10; ++i)
    {
        v.push_back(i);
    }
    long long num = count_if(v.begin(), v.end(), GreatThanFour());
    cout << num;

}

int main()
{
    test012345();
    return 0;
}
