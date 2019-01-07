#include "widget.h"
#include "ui_widget.h"
#include <QTableWidgetItem>
#include <QList>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    
    ui->treeWidget->setHeaderLabels(QStringList()<<"姓名"<<"属性");
    QTreeWidgetItem* ll = new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem* mj = new QTreeWidgetItem(QStringList()<<"敏捷");
    QTreeWidgetItem* xh = new QTreeWidgetItem(QStringList()<<"消耗");
    QList<QTreeWidgetItem*> v;
    v.push_back(ll);v.push_back(mj);v.push_back(xh);
    ui->treeWidget->addTopLevelItems(v);
    QTreeWidgetItem* ll1 = new QTreeWidgetItem(QStringList()<<"德玛"<<"伤害适中，防御适中，血量适中");
    QTreeWidgetItem* ll2 = new QTreeWidgetItem(QStringList()<<"盾山"<<"伤害极低，防御极高，血量适中");
    QTreeWidgetItem* mj1 = new QTreeWidgetItem(QStringList()<<"韩信"<<"不会玩");
    QTreeWidgetItem* xh1 = new QTreeWidgetItem(QStringList()<<"苏妲己"<<"伤害极高，防御极地，血量极低");
    ll->addChild(ll1);ll->addChild(ll2);
    mj->addChild(mj1);
    xh->addChild(xh1);
    
}

Widget::~Widget()
{
    delete ui;
}
