#include <iostream>
#include <fstream>

using namespace std;

void test01()
{
    ofstream ofs;
    ofs.open("./test.txt", ios::out | ios::trunc);

    if(!ofs.is_open())
    {
        cout << "文件打开失败" << endl;
    }
    ofs << "姓名: " << "Hua" << endl;
    ofs << "年龄: " << 22 << endl;

    ofs.close();
}

void test02()
{
    ifstream ifs;
    ifs.open("./test.txt", ios::in);
    if(!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
    }

    char buf[1024];

    while (ifs>>buf)
    {
        cout << buf << endl;
    }
    ifs.close();
}

void test03()
{
    ifstream ifs;
    ifs.open("./test.txt", ios::in);
    if(!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
    }

    char buf[1024];

    while (!ifs.eof())
    {
        ifs.getline(buf,sizeof (buf));
        cout << buf << endl;
    }
    ifs.close();
}

void test04()
{
    ifstream ifs;
    ifs.open("./test.txt", ios::in);
    if(!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
    }

    char c;

    while ((c=ifs.get())!=EOF)
    {
        cout << c;
    }
    ifs.close();
}

int main()
{
    system("chcp 65001");

    test04();
    return 0;
}
