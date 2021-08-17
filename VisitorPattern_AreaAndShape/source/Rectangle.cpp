#include <cstdlib>
#include "../include/Rectangle.h"
#include "../include/ShapeVisitor.h"

CRectangle::CRectangle(int p_Width, int p_Height) : m_Width(p_Width) , m_Height(p_Height)
{
}

CRectangle::CRectangle(const Point& p_LDiagCord, const Point& R_LDiagCord)
{
    m_Width = abs(p_LDiagCord.first - R_LDiagCord.first);
    m_Height = abs(p_LDiagCord.second - R_LDiagCord.second);
}

CRectangle::~CRectangle()
{
}

void CRectangle::Accept(IShapeVisitor* p_Visitor)
{
    if (p_Visitor) p_Visitor->Visit(this);
}

int CRectangle::GetWidth()
{
    return m_Width;
}

int CRectangle::GetHeight()
{
    return m_Height;
}
