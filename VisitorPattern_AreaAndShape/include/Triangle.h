#pragma once 

#include <vector>
#include <utility>

#include "../include/Shape.h"

class CTriangle : public IShape
{
private:
    int m_Width = 0;
    int m_Height = 0;
    std::vector<Point> m_Vertexes;

public:
    CTriangle() {};
    CTriangle(int p_Width, int p_Height);
    CTriangle(int p_X1, int p_Y1, int p_X2, int p_Y2, int p_X3, int p_Y3);
    CTriangle(Point& p_Vertex1, Point& p_Vertex2, Point& p_Vertex3);
    CTriangle(std::vector<Point>& p_Cords);
    ~CTriangle();
 
    void Accept(IShapeVisitor* p_Visitor);
    int GetWidth();
    int GetHeight();
    std::vector<Point> GetVertexes() {return m_Vertexes; }
};
