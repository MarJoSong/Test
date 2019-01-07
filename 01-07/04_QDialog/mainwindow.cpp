#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QColorDialog>
#include <QColor>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    connect(ui->actionNew, &QAction::triggered, this, [=](){
        QDialog dlg(this);
        dlg.resize(200, 100);
        dlg.exec();
    });
    
    connect(ui->actionOpen, &QAction::triggered, this, [=](){
        //创建到栈上，一闪而过
        //QDialog dlg(this);
//        QDialog* dlg2 = new QDialog(this);
//        dlg2->resize(200, 100);
//        dlg2->show();
//        dlg2->setAttribute(Qt::WA_DeleteOnClose);
//        QMessageBox::critical(this, "错误!", "程序崩溃");
//        QMessageBox::information(this, "提示!", "提示信息");
//        QMessageBox::about(this, "关于!", "关于作者");
//        if(QMessageBox::Save == QMessageBox::question(this, "疑问？", "请求帮助？",QMessageBox::Save | QMessageBox::Cancel))
//        {
//            qDebug() << "保存";    
//        }
//        else 
//        {
//            qDebug() << "取消";    
//        }
        
//       QColor color = QColorDialog::getColor(QColor(255,0,0));
//       qDebug() << color.red() << color.green() << color.blue();
        
        QString path = QFileDialog::getOpenFileName(this, "打开文件", "/home/ms/Documents/Debug/02_SignalAndSlots-Debug", "代码文件(*.h *.cpp);;视频文件(*.avi *.mkv)");
        qDebug() << path;
    });
    
}

MainWindow::~MainWindow()
{
    delete ui;
}
