#include "CommandCreateRectangle.h"
#include "Canvas.h"

CommandCreateRectangle::CommandCreateRectangle(const Util::Command& p_Cmd)
{
    m_Cmd = p_Cmd;
}

CommandCreateRectangle::~CommandCreateRectangle()
{

}

void CommandCreateRectangle::Execute()
{
    ICanvas* canvasInst = CANVAS_MANAGER->GetCanvasInFocus();
    if (!canvasInst) return;

    Canvas* canvas = dynamic_cast<Canvas*>(canvasInst);
    if (!canvas) return;

    canvas->CreateRectangle(m_Cmd.points);
}


