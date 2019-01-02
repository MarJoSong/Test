#include <iostream>

using namespace std;

namespace LOL {
    int WuKong = 10;
}

void test()
{
    int WuKong = 20;

    //using 声明
    //using LOL::WuKong;

    //using 编译，只打开空间，4.5如果局部范围内还有 sunwukongID ,使用局部的ID
    //但如果打开多个房间，那么也要注意二义性问题
    using namespace LOL;

    cout << WuKong << endl;//就近原则,当使用using声明时再test作用域中有两个WuKong，出现二义性
    cout << LOL::WuKong << endl;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
