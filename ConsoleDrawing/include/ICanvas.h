#pragma once
#include <vector>
#include"MyUtils.h"

using namespace std;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, -1, 0, 1};

class CommandFill;
class CommandCreateLine;
class CommandCreateRectangle;

using namespace std;

class ICanvas
{
public:
    virtual void CreateLine(const vector<Point>& p_Points) = 0;
    virtual void CreateRectangle(const vector<Point>& p_Points) = 0;
    virtual void ColorFill(const vector<Point>& p_Points, const int p_Color) = 0;

    virtual vector<vector<char>> GetCanvasView() = 0;

    virtual void PerformRedo() = 0;
    virtual void PerformUndo() = 0;

    virtual ~ICanvas(){}
};
