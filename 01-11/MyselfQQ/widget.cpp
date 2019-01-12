#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent, QString name) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::closeEvent(QCloseEvent *e)
{
    emit this->widgetClose();
    QWidget::closeEvent(e);
}
