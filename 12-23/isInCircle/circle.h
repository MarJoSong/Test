#pragma once
#include "point.h"

class Circle
{
    Point m_C;
    int m_R;
public:
    void setCenter(Point p);
    void setR(int r);
    Point& getCenter();
    int& getR();
    void isInCircle(Point p);
};

