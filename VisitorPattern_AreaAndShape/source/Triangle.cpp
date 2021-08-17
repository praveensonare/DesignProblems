#include "../include/Triangle.h"
#include "../include/ShapeVisitor.h"

CTriangle::CTriangle(int p_Width, int p_Height) : m_Width(p_Width), m_Height(p_Height)
{
}

CTriangle::CTriangle(int p_X1, int p_Y1, int p_X2, int p_Y2, int p_X3, int p_Y3)
{
    m_Vertexes.emplace_back(Point(p_X1, p_Y1));
    m_Vertexes.emplace_back(Point(p_X2, p_Y2));
    m_Vertexes.emplace_back(Point(p_X3, p_Y3));
}

CTriangle::CTriangle(Point& p_Vertex1, Point& p_Vertex2, Point& p_Vertex3)
{
    m_Vertexes.emplace_back(p_Vertex1);
    m_Vertexes.emplace_back(p_Vertex2);
    m_Vertexes.emplace_back(p_Vertex3);
}

CTriangle::CTriangle(std::vector<Point>& p_Vertexes)
{
    m_Vertexes = p_Vertexes; 
}

CTriangle::~CTriangle()
{
}

void CTriangle::Accept(IShapeVisitor* p_Visitor)
{
    if (p_Visitor) p_Visitor->Visit(this);
}
 
int CTriangle::GetWidth()
{
    return m_Width;
}

int CTriangle::GetHeight()
{
    return m_Height;
}
