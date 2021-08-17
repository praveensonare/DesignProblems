#pragma once

#include <vector>
#include <utility>
#include <math.h>

using namespace std;

struct Point
{
    int x, y;
    Point() : x(0), y(0){}
    Point(const int _x, const int _y) : x(_x), y(_y) {}

    bool operator == (const Point& p)
    {
        return ((x == p.x) && (y == p.y));
    }

    bool operator < (const Point& p)
    {
        return ((x <= p.x) && (y <= p.y));
    }
};



namespace Util {

    enum CommandType
    {
        CREATE_CANVAS,
        CREATE_LINE,
        CREATE_RECTANGLE,
        COLOR_FILL,
        QUIT,

        ALL_CANVAS_DISPLAY,
        SELECT_CANVAS,
        DELETE,
        UNDO,
        REDO,

        UNKNOWN
    };


    struct Command
    {
        CommandType type;
        vector<Point> points;
        unsigned color;
    };

    CommandType CommandTypeFromChar(const char ch);
    int bound(int val, int low, int high);
}
