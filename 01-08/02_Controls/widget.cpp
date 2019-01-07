#include "widget.h"
#include "ui_widget.h"
#include <QListWidgetItem>
#include <QStringList>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    
    ui->rBtnMan->setChecked(true);
    QListWidgetItem* item = new QListWidgetItem("宋玉华");
    ui->listWidget->addItem(item);
    item->setTextAlignment(Qt::AlignHCenter);
    
    QStringList strlist;
    strlist << "A" << "B" << "C";
    ui->listWidget->addItems(strlist);
    ui->listWidget->addItems(QStringList()<<"D"<<"E");
}

Widget::~Widget()
{
    delete ui;
}
