#include <iostream>
#include <queue>

using namespace std;

void test()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    while (!q.empty())
    {
        cout << "队列头: " << q.front() << endl;
        cout << "队列尾: " << q.back() << endl;
        cout << "----------------" << endl;
        q.pop();
    }
    cout << q.size() << endl;
}

int main()
{
    system("chcp 65001");

    test();
    return 0;
}
