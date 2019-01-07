#include "mywidget.h"
#include <QPushButton>
#include "mybutton.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton* btn = new QPushButton;
    //btn->show();

    btn->setParent(this);
    btn->setText("SanShangYouYa");

    QPushButton* btn2 = new QPushButton("LongSeLuoLa", this);
    this->resize(400, 300);
    btn2->move(100, 100);
    btn2->resize(100, 50);

    this->setWindowTitle("计算机");
    this->setFixedSize(600, 400);

    MyButton* btn3 = new MyButton;
    btn3->move(250, 100);
    btn3->setText("Hello");
    btn3->setParent(this);

    connect(btn3, &MyButton::clicked, this, &MyWidget::close);
}

MyWidget::~MyWidget()
{
    qDebug() << "MyWidget";
}
