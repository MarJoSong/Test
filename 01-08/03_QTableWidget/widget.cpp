#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    
    QStringList str;
    str << "姓名" << "性别" << "年龄";
    ui->tableWidget->setColumnCount(str.size());
    ui->tableWidget->setHorizontalHeaderLabels(str);
    ui->tableWidget->setRowCount(5);
    
    //ui->tableWidget->setItem(0,0,new QTableWidgetItem("亚瑟"));
    QStringList name;
    name << "撒啊啊从" <<"萨顶顶"<<"烦烦烦风"<<"而不"<<"的恶女";
    QList<QString> sex;
    sex << "男" << "女" << "男" << "女" << "男";
    
    for (int i=0;i<5;++i) 
    {
        int col=0;
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(name[i]));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(sex[i]));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(i+18)));
    }
    
    connect(ui->btnAdd,&QPushButton::clicked,this,[=](){
        bool isEmpty = ui->tableWidget->findItems("花花",Qt::MatchExactly).empty();
        if(isEmpty)
        {
            ui->tableWidget->insertRow(0);
            ui->tableWidget->setItem(0,0,new QTableWidgetItem("花花"));
            ui->tableWidget->setItem(0,1,new QTableWidgetItem("男"));
            ui->tableWidget->setItem(0,2,new QTableWidgetItem(QString::number(23)));
        }
        else 
        {
            QMessageBox::warning(this,"警告","花花有了");    
        }
    });
    
    connect(ui->btnDel,&QPushButton::clicked,this,[=](){
        bool isEmpty = ui->tableWidget->findItems("花花",Qt::MatchExactly).empty();
        if(!isEmpty)
        {
            int row = ui->tableWidget->findItems("花花",Qt::MatchExactly).first()->row();
            ui->tableWidget->removeRow(row);
        }
        else 
        {
            QMessageBox::warning(this,"警告","花花没了");    
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
