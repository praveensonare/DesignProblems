#include "CommandFill.h"
#include "Canvas.h"

CommandFill::CommandFill(const Util::Command& p_Cmd)
{
    m_Cmd = p_Cmd;
}

CommandFill::~CommandFill()
{

}

void CommandFill::Execute()
{
    ICanvas* canvasInst = CANVAS_MANAGER->GetCanvasInFocus();
    if (!canvasInst) return;

    Canvas* canvas = dynamic_cast<Canvas*>(canvasInst);
    if (!canvas) return;

    canvas->ColorFill(m_Cmd.points, m_Cmd.color);
}


