#pragma once

class Point
{
    int m_X;
    int m_Y;
public:
    void setX(int x);
    void setY(int y);
    int& getX();
    int& getY();
};
