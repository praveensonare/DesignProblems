#include <iostream>
#include <vector>

#include "../include/Shape.h"
#include "../include/Circle.h"
#include "../include/Triangle.h"
#include "../include/Rectangle.h"
#include "../include/AreaVisitor.h"

void AddTestForCircle(std::vector<IShape*>& p_Shapes)
{
    // different scenario for circle
    p_Shapes.emplace_back(new CCircle());
    p_Shapes.emplace_back(new CCircle(1,2,3));
    p_Shapes.emplace_back(new CCircle(Point(1,2), 1));
}

void AddTestForTriangle(std::vector<IShape*>& p_Shapes)
{
    // different scenario for triangle
    std::vector<Point> triangle_cords;
    triangle_cords.emplace_back(Point(0, 0));
    triangle_cords.emplace_back(Point(10, 0));
    triangle_cords.emplace_back(Point(10, 8));
    p_Shapes.emplace_back(new CTriangle());
    p_Shapes.emplace_back(new CTriangle(10, 8));
    p_Shapes.emplace_back(new CTriangle(0, 0, 10, 0, 10, 8));
    p_Shapes.emplace_back(new CTriangle(triangle_cords[0], triangle_cords[1], triangle_cords[2]));
    p_Shapes.emplace_back(new CTriangle(triangle_cords));
}

void AddTestForRectangle(std::vector<IShape*>& p_Shapes)
{
    // different scenario for rectangle
    p_Shapes.emplace_back(new CRectangle());
    p_Shapes.emplace_back(new CRectangle(3, 7));
    p_Shapes.emplace_back(new CRectangle(Point(4,6), Point(9, 3)));
    p_Shapes.emplace_back(new CRectangle(Point(4,6), Point(1, 1)));
}

int main()
{
    std::vector<IShape*> shapes;
    AddTestForCircle(shapes);
    AddTestForTriangle(shapes);
    AddTestForRectangle(shapes);

    CAreaVisitor* area = new CAreaVisitor();
    // RunAll scenarios using AreaViaitor
    for (auto shape : shapes)
    {
        shape->Accept(area);
    }

    //cleanUp
    for (auto shape : shapes)
    {
        if (shape) delete shape;
    }

    if (area) delete area;

    return 0;
}
