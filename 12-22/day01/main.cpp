#include <iostream>

using namespace std;

int a = 10;

namespace A {
namespace B {
    int a = 30;
}
}

namespace A {
namespace B {
    int b = 40;
}
}

namespace  {
    int c;
}

//可以起别名
namespace nick = A::B;
int main()
{
    int a = 20;
    cout << a << endl;
    cout << ::a << endl;//双冒号为全局作用域
    cout << A::B::a << "\t" << nick::b << endl;//namespace可以嵌套,且可以随时加入新的成员,可以起别名
    cout << c << endl;//匿名namespace的成员为static
    return 0;
}
