#include <iostream>
#include <string.h>
using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "Animal构造" << endl;
    }
    virtual void speak() = 0;

//    virtual ~Animal()
//    {
//        cout << "Animal析构" << endl;
//    }
    virtual ~Animal() = 0;//如果是纯析构函数，需要在类外实现，且这个类也是抽象类，不能实例化
};
Animal::~Animal()
{
    cout << "Animal析构" << endl;
}

class Cat:public Animal
{
public:
    Cat(const char* name)
    {
        cout << "Cat构造" << endl;
        m_Name = new char[strlen(name)+1];
        strcpy(m_Name, name);
    }

    ~Cat()
    {
        cout << "Cat析构" << endl;
        if(nullptr != m_Name)
            delete [] m_Name;
        m_Name = nullptr;
    }

    virtual void speak()
    {
        cout << "猫在喵喵叫" << endl;
    }

private:
    char* m_Name;
};

void test()
{
    Animal* cat = new Cat("pussy");
    cat->speak();

    delete cat;
}

int main()
{
    test();
    return 0;
}
