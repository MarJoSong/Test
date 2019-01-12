#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPicture>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    
//    QPixmap pix(300,300);
//    pix.fill(Qt::white);
    
//    QPainter pen(&pix);
//    pen.setPen(QColor(Qt::green));
//    pen.setRenderHint(QPainter::Antialiasing);
//    pen.drawEllipse(QPoint(150,150), 100, 100);
    
//    pix.save("/home/ms/Desktop/pix.png");
    
//    QImage img(300,300,QImage::Format_RGB32);
//    img.fill(Qt::yellow);
    
//    QPainter painter(&img);
//    painter.setPen(QColor(Qt::green));
//    painter.drawEllipse(QPoint(150,150),100,100);
//    img.save("/home/ms/Desktop/img.png");
    
//    QPicture pic;
//    QPainter pp;
//    pp.begin(&pic);
//    pp.setPen(QColor(Qt::red));
//    pp.drawEllipse(QPoint(150,150),100,100);
//    pp.end();
//    pic.save("/home/ms/Desktop/pic.zt");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
//    QImage img(":/img.png");
    
//    for (int i=0; i<50; ++i) 
//    {
//        for (int j=0; j<50; ++j) 
//        {
//            img.setPixel(i,j,qRgb(255,0,0));
//        }
//    }
    
//    QPainter p(this);
//    p.drawImage(QPoint(0,0), img);
    
    QPicture pic;
    pic.load("/home/ms/Desktop/pic.zt");
    
    QPainter ppic(this);
    ppic.drawPicture(0,0,pic);
}
