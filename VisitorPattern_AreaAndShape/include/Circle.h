#pragma once 

#include "../include/Shape.h"

class CCircle : public IShape
{
private:
    Point m_Center = {0, 0};
    int m_Radius = 0;

public:
    CCircle() {}
    CCircle(const Point& p_Center, int p_Radius);
    CCircle(int p_XCord, int p_YCord, int p_Radius);
    ~CCircle();

    void Accept(IShapeVisitor* p_Vistor);
    Point GetCenter() { return m_Center; }
    int GetRadius() { return m_Radius; }
};
