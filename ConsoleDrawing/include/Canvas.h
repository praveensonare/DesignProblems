#pragma once

#include "ICanvas.h"

#include <iostream>
#include <vector>
#include <deque>
#include <mutex>

class ICommand;

class Canvas : public ICanvas
{
public:
    explicit Canvas(int p_Width, int p_Height);
    ~Canvas();

    void Reset(int p_Width, int p_Height);

    void ColorFill(const vector<Point>& p_Points, const int p_Color);
    void CreateLine(const vector<Point>& p_Points);
    void CreateRectangle(const vector<Point>& p_Points);

    vector<vector<char>> GetCanvasView();
    void PerformRedo();
    void PerformUndo();

private:
    void DrawHorizontalLine(const int y, int x_start, int x_end);
    void DrawVerticalLine(const int x, int y_start, int y_end);

    int m_Width, m_Height;
    vector<vector<unsigned>> m_Mat;
    deque<ICommand*> m_UndoStack;
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, -1, 0, 1};

    static std::once_flag instanceFlag;
    static Canvas *instance;
};
