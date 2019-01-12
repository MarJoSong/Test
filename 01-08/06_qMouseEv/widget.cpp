#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QMouseEvent>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    id1 = startTimer(2000);
    id2 = startTimer(1000);
    
    QTimer* time1 = new QTimer(this);
    time1->start(500);
    connect(time1, &QTimer::timeout, this, [=](){
        static int num = 0;
        ui->label_4->setText(QString::number(num++));
    });
    
    connect(ui->pushButton, &QPushButton::clicked, time1, &QTimer::stop);
    
    ui->label->installEventFilter(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *e)
{
    if(e->timerId()==id1)
    {
        static int num1 = 0;
        ui->label_2->setText(QString::number(num1++));
    }
    if(e->timerId()==id2)
    {
        static int num2 = 0;
        ui->label_3->setText(QString::number(num2++));
    }
}

bool Widget::eventFilter(QObject* obj, QEvent* e)
{
    if(obj == ui->label)
    {
        if(e->type()==QEvent::MouseButtonPress)
        {
            QMouseEvent* ev =static_cast<QMouseEvent*>(e);
            QString str = QString("鼠标按下被事件过滤器拦截和处理, 坐标: (%1, %2)").arg(ev->x()).arg(ev->y());
            qDebug() << str;
            return true;
        }  
    }
    return Widget::eventFilter(obj,e); 
}
