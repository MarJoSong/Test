#include <iostream>

using namespace std;

class Printer
{
private:
    Printer():count(0){}
    Printer(const Printer&p){}

public:
    static Printer* getPrinter()
    {
        return singPrinter;
    }
    void printText(string text)
    {
        cout << text << endl;
        ++count;
        cout << "已使用打印机" << count << "次" << endl;
    }

private:
    static Printer* singPrinter;
    int count;
};
Printer* Printer::singPrinter = new Printer;

void test()
{
    Printer* p = Printer::getPrinter();
    p->printText("应聘简历");
    p->printText("入职申请");
    p->printText("离职申请");
}

int main()
{
    test();

    return 0;
}
