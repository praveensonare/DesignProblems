#include "../include/MyUtils.h"

double CUtils::GetDistance(const Point& p_From, const Point& p_To)
{
    int x = p_From.first - p_To.first;
    int y = p_From.second - p_To.second;

    double distance = sqrt(x*x + y*y);
    return distance;
}

double CUtils::GetArea(const vector<Point>& p_Vertex)
{
    if (p_Vertex.size() != 3) return -1;

    double side1 = GetDistance(p_Vertex[0], p_Vertex[1]);
    double side2 = GetDistance(p_Vertex[1], p_Vertex[2]);
    double side3 = GetDistance(p_Vertex[2], p_Vertex[0]);

    double s = (side1 + side2 + side3) / 2;
    double area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
    return area;
}

