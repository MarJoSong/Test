#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

public slots:
    //自定义槽函数放这里
    //高版本可以写到public，也可以是全局函数
    //必须要实现
    //返回值为void
    //可以有参数，可以重载
    void treat();
    void treat(QString);
};

#endif // STUDENT_H
