#include <iostream>

using namespace std;

class myPrint
{
public:
    void operator()(int num)
    {
        cout << "打印数值: " << num << endl;
        ++count;
    }

    int count = 0;
};

void test()
{
    myPrint p;
    p(11);
    p(11);
    p(11);
    p(11);

    cout << p.count << endl;
}

void doWork(myPrint print, int num)
{
    print(num);
}

int main()
{
    system("chcp 65001");

    //test();
    myPrint p;
    doWork(p, 123);
    return 0;
}
