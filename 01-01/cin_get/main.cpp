#include <iostream>

using namespace std;

void test01()
{
    char ch;
    while ((ch = cin.get())) {
        if(ch == '\0')
        {
            cout << "Get \\0" << endl;
            continue;
        }
        if(ch == '\n')
        {
            cout << "Get \\n" << endl;
            continue;
        }
        cout << ch << endl;
    }
}

void test02()
{
    char ch[1024];
    cin.get(ch, 1024);
    cout << ch << endl;
    if(cin.get())
        cout << "Get \\n" << endl;
}

void test03()
{
    char ch[1024];
    cin.getline(ch, 1024);
    cout << "PrintStart>>" << ch << "<<PrintEnd" << endl;
    if(cin.get())
        cout << "Get \\n" << endl;
}


void test04()
{
    cin.ignore(2);
    char c = cin.get();
    cout << "c = " << c << endl;
    if(cin.get())
        cout << "Get \\n" << endl;
}

void test05()
{
    char c = cin.peek();
    cout << "c = " << c << endl;
    c = cin.get();
    cout << "c = " << c << endl;
}

void test06()
{
    char c = cin.get();
    cin.putback(c);
    cout << "c = " << c << endl;
    char buf[1024];
    cin.getline(buf, 1024);
    cout << "buf = " << buf << endl;
}

int main()
{
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    test06();
    return 0;
}
