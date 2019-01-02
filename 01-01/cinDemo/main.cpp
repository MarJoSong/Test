#include <iostream>

using namespace std;

void test()
{
    int num;

    while (true)
    {
        cin >> num;
        if(num>0 && num<=10)
        {
            cout << "Num: " << num << endl;
            break;
        }
        cout << "Flags: " << cin.fail() << endl;
        cin.clear();
        cin.sync();
        cout << "Flags: " << cin.fail() << endl;
    }
    cout << num << endl;
}

int main()
{
    test();
    return 0;
}
