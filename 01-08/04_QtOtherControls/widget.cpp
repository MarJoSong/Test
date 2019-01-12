#include "widget.h"
#include "ui_widget.h"
#include <QMovie>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    
    ui->stackedWidget->setCurrentIndex(0);
    
    connect(ui->btn1, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    
    connect(ui->btn2, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    
    connect(ui->btn3, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(2);
    });
    
    QMovie* mov = new QMovie(":/110.gif");
    ui->img->setMovie(mov);
    mov->start();
}

Widget::~Widget()
{
    delete ui;
}
