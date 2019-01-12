#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextCodec>
#include <QDebug>
#include <QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    
    connect(ui->pushButton, &QPushButton::clicked, this, [=](){
        QString path = QFileDialog::getOpenFileName(this, "打开文件", "/home/ms/Documents/Git/Test","所有文件(*.*);;C文件(*.c *.cpp *.h)");
        if(path.isEmpty())
        {
            QMessageBox::critical(this, "错误", "打开文件失败");
        }
        else 
        {
            ui->lineEdit->setText(path);   
            
//            QFile file(path);
//            //默认打开方式utf-8
//            file.open(QIODevice::ReadOnly);
            
//            QByteArray array;
//            //array = file.readAll();
//            while (!file.atEnd()) 
//            {
//                array += file.readLine();
//            }
            
//            //设置gbk格式
//            QTextCodec* codec = QTextCodec::codecForName("gbk");
//            ui->textEdit->setText(codec->toUnicode(array));
            
//            //ui->textEdit->setText(array);
//            file.close();
            
//            file.open(QIODevice::Append);
//            file.write("abcdefg");
//            file.close();
            
            QFileInfo info(path);
            qDebug() << "路径: " << info.path() << "\n名称: " << info.fileName() << "\n后缀: " << info.suffix();
            qDebug() << "创建时间: " << info.created().toString("yyyy-MM-dd HH:mm:ss");
            qDebug() << "上次修改时间: " << info.lastModified().toString("yyyy/MM/dd HH:mm:ss");
        }
    });  
//    QFile file("/home/ms/Desktop/aaa.txt");
//    file.open(QIODevice::WriteOnly);
//    QTextStream stream(&file);
//    stream << QString("Hello World") << 123456;
//    file.close();
    
//    file.open(QIODevice::ReadOnly);
//    QString str;
//    //stream >> str;只打印到第一个空白符
//    str = stream.readAll();
//    qDebug() << str; 
    
    QFile file("/home/ms/Desktop/bbb.txt");
    file.open(QIODevice::WriteOnly);
    QDataStream stream(&file);
    stream << QString("Hello World") << 123456;
    file.close();
    
    file.open(QIODevice::ReadOnly);
    QString str;
    int num;
    stream >> str;
    stream >> num;
    qDebug() << str << num;
}

Widget::~Widget()
{
    delete ui;
}
