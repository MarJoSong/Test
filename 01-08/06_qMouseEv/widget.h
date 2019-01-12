#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    
    void timerEvent(QTimerEvent* e);
    bool eventFilter(QObject*, QEvent*);
    
private:
    Ui::Widget *ui;
    int id1;
    int id2;
};

#endif // WIDGET_H
