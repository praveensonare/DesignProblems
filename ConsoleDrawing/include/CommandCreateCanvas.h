#pragma once

#include "ICommand.h"


class CommandCreateCanvas : public ICommand
{
public:
    CommandCreateCanvas(){}
    CommandCreateCanvas(const Util::Command& p_Cmd);
    ~CommandCreateCanvas();

    void Execute();

private:
    void CreateCanvas();
};
