#include "dialoglist.h"
#include "ui_dialoglist.h"
#include <QToolButton>
#include <widget.h>
#include <QMessageBox>

DialogList::DialogList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogList)
{
    ui->setupUi(this);
    
    this->setWindowTitle("深度QQ v1.0");
    this->setWindowIcon(QPixmap(":/images/QQ_Penguin.png"));
    
    QList<QString>nameList;
    nameList << "水票奇缘" << "忆梦如澜" <<"北京出版人"<<"Cherry"<<"淡然"
             <<"娇娇girl"<<"落水无痕"<<"青墨暖暖";
    QStringList iconNameList; //图标资源列表
    iconNameList << "spqy"<< "ymrl" <<"qq" <<"Cherry"<< "dr"
                 <<"jj"<<"lswh"<<"qmnn";
    
    QVector<QToolButton*> vToolBtn;
    for (int i=0;i<8;++i) 
    {
        QToolButton* btn = new QToolButton;
        btn->setText(nameList.at(i));
        QString str = QString(":/images/%1.png").arg(iconNameList.at(i));
        btn->setIcon(QPixmap(str));
        btn->setIconSize(QPixmap(str).size());
        btn->setAutoRaise(true);
        btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        vToolBtn.push_back(btn);
        isShow.push_back(false);
        
        ui->verticalLayout->addWidget(btn); 
    }
    
    for (int i=0; i<vToolBtn.size();++i) 
    {
        connect(vToolBtn[i],&QToolButton::clicked, this, [=](){
            if(isShow[i])
            {
                QMessageBox::warning(this, "警告", "窗口已经打开");
                return;
            }
            isShow[i] = true;
            Widget* chatWidget = new Widget(0, vToolBtn[i]->text());
            chatWidget->setWindowTitle(vToolBtn[i]->text());
            chatWidget->setWindowIcon(vToolBtn[i]->icon());
            chatWidget->show();
            
            connect(chatWidget, &Widget::widgetClose, this,[=](){
                isShow[i]=false;
            });
        });  
        
    }
}

DialogList::~DialogList()
{
    delete ui;
}
