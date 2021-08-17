#include "CommandCreateCanvas.h"
#include "Canvas.h"

CommandCreateCanvas::CommandCreateCanvas(const Util::Command& p_Cmd)
{
    m_Cmd = p_Cmd;
}

CommandCreateCanvas::~CommandCreateCanvas()
{

}

void CommandCreateCanvas::Execute()
{
    int width = m_Cmd.points[0].x;
    int height = m_Cmd.points[0].y;
    Canvas* canvas = new Canvas(width, height);
    CANVAS_MANAGER->AddNewCanvas(canvas);
}
