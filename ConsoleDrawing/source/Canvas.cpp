#include "Canvas.h"

#include <queue>
#include "MyUtils.h"

#define EMPTY_CELL (unsigned)1024

Canvas::Canvas(int p_Width, int p_Height) : m_Width(p_Width), m_Height(p_Height)
{
    m_Mat = vector<vector<unsigned>>(m_Height, vector<unsigned>(m_Width, EMPTY_CELL));
}

Canvas::~Canvas()
{

}

void Canvas::Reset(int p_Width, int p_Height)
{
    m_Width = p_Width;
    m_Height = p_Height;

    m_Mat = vector<vector<unsigned>>(m_Height, vector<unsigned>(m_Width, EMPTY_CELL));
}

void Canvas::ColorFill(const vector<Point>& p_Points, const int p_Color)
{
    if (p_Points.size() != 1 ||
            p_Points[0].x < 0 || p_Points[0].x >= m_Width || p_Points[0].y < 0 || p_Points[0].y >= m_Height)
    {
        std::cerr << "Error : Invalid Point for Color" << endl;
        return;
    }

    queue<Point> Q;
    Point front, nbr;
    Q.push(p_Points.front());

    while (!Q.empty())
    {
        front = Q.front();
        Q.pop();

        if (m_Mat[front.y][front.x] == p_Color || m_Mat[front.y][front.x] > EMPTY_CELL) continue;

        m_Mat[front.y][front.x] = p_Color;

        for (int i = 0; i < 4; ++i)
        {
            nbr.x = front.x + dx[i];
            nbr.y = front.y + dy[i];

            if (nbr.x < 0 || nbr.x >= m_Width || nbr.y < 0 || nbr.y >= m_Height) continue;
            Q.push(nbr);
        }
    }
}

void Canvas::CreateLine(const vector<Point>& p_Points)
{
    if (p_Points[0].x == p_Points[1].x)
    {
        DrawVerticalLine(p_Points[0].x, p_Points[0].y, p_Points[1].y);
    }
    else if (p_Points[0].y == p_Points[1].y)
    {
        DrawHorizontalLine(p_Points[0].y, p_Points[0].x, p_Points[1].x);
    }
}

void Canvas::CreateRectangle(const vector<Point>& p_Points)
{
    DrawVerticalLine(p_Points[0].x, p_Points[0].y, p_Points[1].y);
    DrawVerticalLine(p_Points[1].x, p_Points[0].y, p_Points[1].y);
    DrawHorizontalLine(p_Points[0].y, p_Points[0].x, p_Points[1].x);
    DrawHorizontalLine(p_Points[1].y, p_Points[0].x, p_Points[1].x);
}

vector<vector<char>> Canvas::GetCanvasView()
{
    vector<vector<char>> view(m_Height, vector<char>(m_Width, ' '));

    for (int y = 0; y < m_Height; ++y)
    {
        for (int x = 0; x < m_Width; ++x)
        {
            view[y][x] = (m_Mat[y][x] == EMPTY_CELL) ? ' ' : (m_Mat[y][x] > EMPTY_CELL) ? 'x': (char)m_Mat[y][x];
        }
    }

    return view;
}

void Canvas::DrawHorizontalLine(const int y, int x_start, int x_end)
{
    if (y < 0 || y >= m_Height) return;

    int maxW = m_Width - 1;
    int xStart = Util::bound(x_start, 0, maxW);
    int xEnd = Util::bound(x_end, 0, maxW);

    for (int x = xStart; x <= xEnd; ++x)
    {
        m_Mat[y][x] = max(m_Mat[y][x], EMPTY_CELL) + 1;
    }
}
void Canvas::DrawVerticalLine(const int x, int y_start, int y_end)
{
    if (x < 0 || x >= m_Width) return;

    int maxH = m_Height - 1;
    int yStart = Util::bound(y_start, 0, maxH);
    int yEnd = Util::bound(y_end, 0, maxH);

    for (int y = yStart; y <= yEnd; ++y)
    {
        m_Mat[y][x] = max(m_Mat[y][x], EMPTY_CELL) + 1;
    }

}

void Canvas::PerformUndo()
{

}

void Canvas::PerformRedo()
{

}
