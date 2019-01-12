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
    explicit Widget(QWidget *parent, QString name);
    ~Widget();
    
signals:
    void widgetClose();
    
protected:
    void closeEvent(QCloseEvent* e);
    
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
