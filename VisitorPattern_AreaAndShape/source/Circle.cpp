#include "../include/Circle.h"
#include "../include/ShapeVisitor.h"

CCircle::CCircle(const Point& p_Center, int p_Radius) : m_Center(p_Center), m_Radius(p_Radius)
{
}

CCircle::CCircle(int p_XCord, int p_YCord, int p_Radius) : m_Center({p_XCord, p_YCord}), m_Radius(p_Radius)
{
}

CCircle::~CCircle()
{
}

void CCircle::Accept(IShapeVisitor* p_Visitor)
{
    if (p_Visitor) p_Visitor->Visit(this);
}
