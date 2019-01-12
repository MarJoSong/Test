#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    
    connect(ui->btnSet, &QPushButton::clicked, this, [=](){
        ui->widget->setMedium();
    });
    
    connect(ui->btnRet, &QPushButton::clicked, this, [=](){
        qDebug() << ui->widget->retValue();
    });
}

Widget::~Widget()
{
    delete ui;
}
