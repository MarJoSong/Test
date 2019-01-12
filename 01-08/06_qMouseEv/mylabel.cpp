#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    this->setMouseTracking(true);
}

void MyLabel::enterEvent(QEvent *)
{
    qDebug() << "鼠标进入了!";
}

void MyLabel::leaveEvent(QEvent *)
{
    qDebug() << "鼠标离开了!";
}

void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons() & Qt::LeftButton)
    {
        QString str = QString("鼠标左键移动坐标: (%1, %2)").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }
    else if(ev->buttons() & Qt::RightButton)
    {
        QString str = QString("鼠标右键移动坐标: (%1, %2)").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }
}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    if(Qt::LeftButton == ev->button())
    {
        qDebug() << "鼠标按下被父事件分发";
        QString str = QString("鼠标左键按下坐标: (%1, %2)").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }
    else if(Qt::RightButton == ev->button())
    {
        qDebug() << "鼠标按下被父事件分发";
        QString str = QString("鼠标右键按下坐标: (%1, %2)").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }
}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    if(Qt::LeftButton == ev->button())
    {
        QString str = QString("鼠标左键释放坐标: (%1, %2)").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }
    else if(Qt::RightButton == ev->button())
    {
        QString str = QString("鼠标右键释放坐标: (%1, %2)").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }
}

bool MyLabel::event(QEvent *e)
{
    if(e->type()==QEvent::MouseButtonPress)
    {
        QMouseEvent* ev =static_cast<QMouseEvent*>(e);
        QString str = QString("鼠标按下被父事件拦截和处理, 坐标: (%1, %2)").arg(ev->x()).arg(ev->y());
        qDebug() << str;
        return true;
    }
    return QLabel::event(e);   
}
