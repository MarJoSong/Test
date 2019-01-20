#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>

using namespace std;

class MyPrint :public binary_function<int, int, void>
{
public:
    void operator()(int v, int base) const
    {
        cout << "v=" << v << " base=" << base << " sum=" << v + base << endl;
    }
};

//加法适配器
void test01()
{
    vector<int> v;
    for (int i=0; i<10; ++i)
    {
        v.push_back(i);
    }

    cout << "输入基数: ";
    int num;
    cin >> num;

    for_each(v.begin(), v.end(), bind1st(MyPrint(),num));
    cout << "-----------------------------------------------" << endl;
    for_each(v.begin(), v.end(), bind2nd(MyPrint(),num));
}


class GreatThan :public binary_function<int, int, bool>
{
public:
    bool operator()(int v, int com) const
    {
        return v > com;
    }
};

void test02()
{
    vector<int> v;
    for (int i=0; i<10; ++i)
    {
        v.push_back(i);
    }

    cout << "输入比较数: ";
    int num;
    cin >> num;
    vector<int>::iterator pos = find_if(v.begin(), v.end(), bind2nd(GreatThan(),num));
    if(pos!=v.end())
    {
        cout << "比" << num << "大的数为" << *pos << endl;
        return;
    }
    cout <<"无";
}


//取反适配器
class GreatThan5 :public unary_function<int, bool>
{
public:
    bool operator()(int v) const
    {
        return v > 5;
    }
};
void test03()
{
    vector<int> v;
    for (int i=0; i<10; ++i)
    {
        v.push_back(i);
    }

    //vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(GreatThan5()));
    vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(bind2nd(greater<int>(),5)));
    if(pos!=v.end())
    {
        cout << "比" << 5 << "小的数为" << *pos << endl;
        return;
    }
    cout <<"无";
}

//函数指针适配器
void myPrint(int v, int base)
{
    cout << v+base << endl;
}
void test04()
{
    vector<int> v;
    for (int i=0; i<10; ++i)
    {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), bind2nd(ptr_fun(myPrint),100));
}

//成员函数适配器
class Person
{
public:
    Person(string name, int age)
    {
        m_name = name;
        m_age = age;
    }
    void showPerson()
    {
        cout << m_name << "\t" << m_age << endl;
    }

private:
    string m_name;
    int m_age;
};

void test05()
{
    vector<Person> v;
    Person p1("AAA", 10);
    Person p2("BBB", 20);
    Person p3("CCC", 30);
    Person p4("DDD", 40);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
}

int main()
{
    //test01();
    //test02();
    //test04();
    test05();
    return 0;
}
