#include <iostream>

#include "../include/AreaVisitor.h"
#include "../include/Circle.h"
#include "../include/Triangle.h"
#include "../include/Rectangle.h"
#include "../include/MyUtils.h"

CAreaVisitor::CAreaVisitor()
{
}

CAreaVisitor::~CAreaVisitor()
{
}

void CAreaVisitor::Visit(CCircle* p_Circle)
{
    int radius = p_Circle->GetRadius();
    double area = 3.14 * radius * radius;
    cout << "Area of Circle is : " << area << endl;
}

void CAreaVisitor::Visit(CTriangle* p_Triangle)
{
    vector<pair<int, int>> vertex = p_Triangle->GetVertexes();
    double area = 0;
    if (vertex.size() == 3)
    {
        area = CUtils::GetArea(vertex);
    }
    else
    {
        area = 0.5 * p_Triangle->GetWidth() * p_Triangle->GetHeight();
    }
    cout << "Area of Triangle is : " << area << endl;
}

void CAreaVisitor::Visit(CRectangle* p_Rectangle)
{
    double area = p_Rectangle->GetWidth() * p_Rectangle->GetHeight();
    cout << "Area of Rectangle is : " << area << endl;
}
