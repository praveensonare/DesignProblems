#pragma once
#include <string>
#include "CommandParser.h"
#include "CanvasManager.h"

using namespace std;
#define CANVAS_MANAGER CanvasManager::GetInstance()

class ICommand
{
    public:
    virtual ~ICommand(){}
    virtual void Execute() = 0;
    virtual void SetCommand(Util::Command p_Cmd) { m_Cmd = p_Cmd; }

    Util::Command m_Cmd;
};
