#include "CommandFactory.h"
#include <iostream>
#include <map>
#include "CommandCreateCanvas.h"
#include "CommandCreateLine.h"
#include "CommandCreateRectangle.h"
#include "CommandFill.h"
#include "CommandQuit.h"

CommandFactory::CommandFactory()
{
}

ICommand* CommandFactory::CreateCommandObj(const Util::Command& p_Cmd)
{
    static map<Util::CommandType, ICommand*> CommandObj {
        {Util::CREATE_CANVAS, new CommandCreateCanvas()},
        {Util::CREATE_LINE, new CommandCreateLine()},
        {Util::CREATE_RECTANGLE, new CommandCreateRectangle()},
        {Util::COLOR_FILL, new CommandFill()},
        {Util::QUIT, new CommandQuit()}
    };

    switch (p_Cmd.type) {

    case Util::CREATE_CANVAS:
        if (p_Cmd.points.empty())
        {
            std::cerr << "Invalid Canvas Size" << endl;
            return nullptr;
        }
        break;

    case Util::CREATE_LINE:
        if (p_Cmd.points.size() != 2)
        {
            std::cerr << "Invalid number of points" << endl;
            return nullptr;
        }
        break;

    case Util::CREATE_RECTANGLE:
        if (p_Cmd.points.size() != 2)
        {
            std::cerr << "Invalid number of points, needed let top and right bottom cordinates" << endl;
            return nullptr;
        }
        break;

    case Util::COLOR_FILL:
        if (p_Cmd.points.size() != 1)
        {
            std::cerr << "Invalid input, needed start coloring position" << endl;
            return nullptr;
        }
        break;

    case Util::QUIT:
        break;

    default:
        return nullptr;
    }

    CommandObj[p_Cmd.type]->SetCommand(p_Cmd);
    return CommandObj[p_Cmd.type];
}
