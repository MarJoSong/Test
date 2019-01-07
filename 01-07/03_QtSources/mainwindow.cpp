#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    
    ui->actionNew->setIcon(QIcon(":/image/img/apple.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
