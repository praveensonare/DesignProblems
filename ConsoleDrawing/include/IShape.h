#pragma once 

#include "MyUtils.h"

class IDrawing;

class IShape
{
public:
    virtual ~IShape() {}
    virtual void Accept(IDrawing* p_Vsitor) = 0;
};

