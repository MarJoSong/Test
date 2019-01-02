#include <iostream>
#include "point.h"
#include "circle.h"

using namespace std;

void isInCircle(Circle c, Point p)
{
    int dd = (c.getCenter().getX()-p.getX())*(c.getCenter().getX()-p.getX()) + (c.getCenter().getY()-p.getY())*(c.getCenter().getY()-p.getY());
    int rr = c.getR()*c.getR();
    if(dd == rr)
    {
        cout << "在圆上" << endl;
    }
    else if (dd < rr)
    {
        cout << "在圆内" << endl;
    }
    else
    {
        cout << "在圆外" << endl;
    }
}

void test01()
{
    Point p1;
    p1.setX(10);
    p1.setY(9);

    Circle c1;
    Point pc;
    pc.setX(10);
    pc.setY(0);
    c1.setCenter(pc);
    c1.setR(10);
    isInCircle(c1,p1);
}

void test02()
{
    Point p1;
    p1.setX(10);
    p1.setY(6);

    Circle c1;
    Point pc;
    pc.setX(10);
    pc.setY(0);
    c1.setCenter(pc);
    c1.setR(10);
    c1.getR() = 5;
    c1.isInCircle(p1);
}

int main()
{
    //test01();
    test02();
    return 0;
}
