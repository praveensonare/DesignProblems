#pragma once

#include "../include/ShapeVisitor.h"

class CAreaVisitor : public IShapeVisitor
{
public:
    CAreaVisitor();
    ~CAreaVisitor();

    void Visit(CCircle* p_Circle);
    void Visit(CTriangle* p_Triangle);
    void Visit(CRectangle* p_Rectangle);
};
