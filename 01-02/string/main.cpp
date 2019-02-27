#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

void test()
{
    string str = "Hello World";

    for (size_t i=0; i<str.size(); ++i)
    {
        cout << str.at(i) << endl;
    }
    cout << "----------------" << endl;

    for (size_t i=0; i<str.size(); ++i)
    {
        cout << str[str.size()-i-1]<< endl;
    }

    //[]和at区别：在访问越界时，[]可能挂掉，at抛出异常
    //cout << str[100];

    cout << str.at(100);

}

int main()
{
    system("chcp 65001");
    try {
        test();
    } catch (out_of_range& e) {
        cout << "越界异常" << endl;
        cout << e.what() << endl;
    }

    return 0;
}
