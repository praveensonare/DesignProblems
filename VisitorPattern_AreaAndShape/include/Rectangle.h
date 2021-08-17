#pragma once 

#include "../include/Shape.h"

class CRectangle : public IShape
{
private:
    Point m_LDiagCord = {0, 0}; // left cord of a diagonal
    Point m_RDiagCord = {0, 0}; // right cord of a diagonal
    int m_Width = 0;
    int m_Height = 0;

public:
    CRectangle() {};
    CRectangle(int p_Width, int p_Height);
    CRectangle(const Point& p_LDiagCord, const Point& R_LDiagCord);
    ~CRectangle();

    void Accept(IShapeVisitor* p_Visitor);
    int GetWidth();
    int GetHeight();
};
