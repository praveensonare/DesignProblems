#pragma once 

#include "../include/ShapeVisitor.h"
#include "../include/MyUtils.h"

class IShapeVisitor;

class IShape
{
public:
    virtual ~IShape() {}
    virtual void Accept(IShapeVisitor* p_Vsitor) = 0;
};

