#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QLabel>
#include <QStatusBar>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(600, 400);
    
    QMenuBar* bar = menuBar();
    QMenu* newMenu = bar->addMenu("文件");
    QMenu* editMenu = bar->addMenu("编辑");
    
    QAction* newFile = newMenu->addAction("新建");
    newMenu->addSeparator();
    QAction* openFile = newMenu->addAction("打开");
    
    QToolBar* toolBar = new QToolBar("工具栏", this);
    this->addToolBar(Qt::LeftToolBarArea, toolBar);
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    toolBar->setFloatable(false);
    toolBar->setMovable(false);
    toolBar->addAction(newFile);
    toolBar->addSeparator();
    toolBar->addAction(openFile);
    
    QStatusBar* sBar = statusBar();
    this->setStatusBar(sBar);
    QLabel* label = new QLabel("提示信息", this);
    sBar->addWidget(label);
    QLabel* label2 = new QLabel("右侧提示信息", this);
    sBar->addPermanentWidget(label2);
    
    QDockWidget* dock = new QDockWidget();
    this->addDockWidget(Qt::BottomDockWidgetArea, dock);
    dock->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);
    QTextEdit* textEdit = new QTextEdit();
    this->setCentralWidget(textEdit);
}

MainWindow::~MainWindow()
{
    
}
