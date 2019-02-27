#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void test01()
{
    int arr[] = {1, 3, 5, 5, 7};
    for (int i=0; i<5; ++i)
    {
        cout << *(arr+i) << endl;
    }
}

void test02()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    vector<int>::iterator itBegin = v.begin();
    vector<int>::iterator itEnd = v.end();

//    while (itBegin != itEnd)
//    {
//        cout << *itBegin << endl;
//        ++itBegin;
//    }

    for (vector<int>::iterator it = v.begin(); it!=v.end(); ++it)
    {
        cout << *it << endl;
    }
}


void myPrint(int v)
{
    cout << v << endl;
}

void test03()
{
    vector<int> v;
    v.push_back(11);
    v.push_back(22);
    v.push_back(33);
    v.push_back(44);

    for_each(v.begin(), v.end(), myPrint);
}

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

void test04()
{
    Person p1("Tom", 10);
    Person p2("Jack", 12);

    vector<Person> v;
    v.push_back(p1);
    v.push_back(p2);

    for (vector<Person>::iterator it=v.begin(); it!=v.end(); ++it)
    {
        cout << (*it).m_Name << " " << (*it).m_Age << endl;
    }
}

void test05()
{
    vector<vector<int>> vf;
    vector<int> vz1;
    vector<int> vz2;
    vector<int> vz3;

    for (int i=0; i<3; ++i)
    {
        vz1.push_back(i);
        vz2.push_back(i+10);
        vz3.push_back(i+100);
    }
    vf.push_back(vz1);
    vf.push_back(vz2);
    vf.push_back(vz3);

    for (vector<vector<int>>::iterator it=vf.begin(); it!=vf.end(); ++it)
    {
        for (vector<int>::iterator itz=it->begin(); itz!=it->end(); ++itz)
        {
            cout << *itz << " ";
        }
        cout << endl;
    }
}

int main()
{
    test05();
    return 0;
}
