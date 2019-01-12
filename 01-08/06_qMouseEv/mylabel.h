#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);
    
protected:
    void enterEvent(QEvent*);
    void leaveEvent(QEvent*);

    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);  
    
    bool event(QEvent* e);
};

#endif // MYLABEL_H
