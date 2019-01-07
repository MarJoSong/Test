#include "widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    tea = new Teacher(this);
    stu = new Student(this);
    
    this->setFixedSize(600, 400);
    /*
    //非重载写法
    connect(tea, &Teacher::hungry, stu, &Student::treat);
    */
    
    /*
    //重载后要用函数指针
    void (Teacher::*teaSignal)(QString) = &Teacher::hungry;
    void (Student::*stuSlots)(QString) = &Student::treat;
    connect(tea, teaSignal, stu, stuSlots);
    */
    
    QPushButton* btn = new QPushButton("下课", this);
    void (Teacher::*teaSignalNo)(void) = &Teacher::hungry;
    void (Student::*stuSlotsNo)(void) = &Student::treat;
    connect(btn, &QPushButton::clicked, tea, teaSignalNo);
    connect(tea, teaSignalNo, stu, stuSlotsNo);
    //disconnect(tea, teaSignalNo, stu, stuSlotsNo);
    
    //Qt4写法，不检测参数
    connect(tea, SIGNAL(hungry(QString)), stu, SLOT(treat(QString)));
    this->ClassisOver();
    
    
    int m = 10;
    QPushButton* btn1 = new QPushButton("btn1", this);
    QPushButton* btn2 = new QPushButton("btn2", this);
    btn1->move(100, 0);
    btn2->move(200, 0);
    //按值传递是默认不可修改，若想修改，加mutable关键字，修改不影响原值
    connect(btn1, &QPushButton::clicked, this, [m]()mutable{m=m+100;qDebug()<<m;});
    connect(btn2, &QPushButton::clicked, this, [=](){qDebug()<<m;});
    
    //返回值
    int ret = []()->int{return 1000;}();
    qDebug() << "ret = " << ret;
    
    connect(btn, &QPushButton::clicked, this, [=](){
        btn->setText("DDDD");
    });
    
    connect(btn1, &QPushButton::clicked, this, [=](){
        tea->hungry("GeiBaDan");
    });
    
    //当lamba里面只用，this时，connect里的this可以省略
    connect(btn2, &QPushButton::clicked, [=](){
        this->close();
    });   
}

Widget::~Widget()
{
}

void Widget::ClassisOver()
{
    //emit tea->hungry();
    emit tea->hungry("麻婆豆腐");
}
