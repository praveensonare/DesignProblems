#pragma once

#include <vector>
#include <utility>
#include <math.h>

using namespace std;
typedef std::pair<int, int> Point;

// this is a utility class for generic functionality
class CUtils
{
public:
    static double GetDistance(const Point& p_From, const Point& p_To);
    static double GetArea(const std::vector<Point>& p_Vertex);
};
