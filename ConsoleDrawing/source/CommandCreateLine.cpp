#include "CommandCreateLine.h"
#include "Canvas.h"

CommandCreateLine::CommandCreateLine(const Util::Command& p_Cmd)
{
    m_Cmd = p_Cmd;
}

CommandCreateLine::~CommandCreateLine()
{

}

void CommandCreateLine::Execute()
{
    ICanvas* canvasInst = CANVAS_MANAGER->GetCanvasInFocus();
    if (!canvasInst) return;

    Canvas* canvas = dynamic_cast<Canvas*>(canvasInst);
    if (!canvas) return;

    canvas->CreateLine(m_Cmd.points);
}


