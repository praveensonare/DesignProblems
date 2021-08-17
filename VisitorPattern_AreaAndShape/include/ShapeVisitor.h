#pragma once 

#include "../include/Shape.h"

class CCircle;
class CTriangle;
class CRectangle;

class IShapeVisitor
{
public:
    virtual ~IShapeVisitor() {}
    
    virtual void Visit(CCircle* p_Circle) = 0;
    virtual void Visit(CTriangle* p_Triangle) = 0;
    virtual void Visit(CRectangle* p_Rectangle) = 0;
};

