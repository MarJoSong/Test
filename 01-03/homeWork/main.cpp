#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
#include <ctime>

using namespace std;

class Person
{
public:
    Person(string name)
    {
        this->m_Name = name;
    }
    deque<int> score;
    int sumscore = 0;
    double sscore;
    string m_Name;
};

bool myCompare(int v1, int v2)
{
    return v1 < v2;
}

void printDeque(deque<int>& d)
{
    for (deque<int>::iterator it=d.begin(); it!=d.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test()
{
    vector<Person> demo;
    demo.push_back(Person("A"));
    demo.push_back(Person("B"));
    demo.push_back(Person("C"));
    demo.push_back(Person("D"));
    demo.push_back(Person("E"));

    srand(static_cast<unsigned int>(time(nullptr)));
    for (vector<Person>::iterator it = demo.begin(); it!=demo.end(); ++it)
    {
        for (int i=0; i<10; ++i)
        {
            it->score.push_back(rand()%5+6);
        }
        sort(it->score.begin(), it->score.end());
        printDeque(it->score);
        it->score.pop_front();
        it->score.pop_back();
        printDeque(it->score);
    }

    for (vector<Person>::iterator it = demo.begin(); it!=demo.end(); ++it)
    {
        for (deque<int>::iterator subIt = it->score.begin(); subIt!= it->score.end(); ++subIt)
        {
            it->sumscore += *subIt;
        }
        it->sscore = it->sumscore*1.0/static_cast<double>(it->score.size());
        cout << it->m_Name << "平均分: " << it->sscore << endl;
    }

}

int main()
{
    system("chcp 65001");
    test();
    return 0;
}
