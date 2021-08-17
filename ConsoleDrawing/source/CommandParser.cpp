#include "CommandParser.h"
#include <iostream>

Util::Command CommandParser::ReadInputFromUser()
{
    while (true)
    {
        DisplayMenu();
        Util::Command cmd;
        char type;
        cin >> type;
        cmd.type = Util::CommandTypeFromChar(type);

        switch(cmd.type)
        {
            case Util::CREATE_CANVAS:
            ReadCreateCanvasInput(cmd);
            return cmd;

        case Util::CREATE_LINE:
            ReadCreateLineInput(cmd);
            return cmd;

        case Util::CREATE_RECTANGLE:
            ReadCreateRectangleInput(cmd);
            return cmd;

        case Util::COLOR_FILL:
            ReadColorFillInput(cmd);
            return cmd;

        case Util::QUIT:
            return cmd;

        default:
            std::cerr << "Invalid Command. Retry - " << endl;
            break;
        }
    }
}

void CommandParser::ReadCreateCanvasInput(Util::Command& p_Cmd)
{
    Point p = ReadTwoInteger(INPUT_CANVAS_DIMENTION);
    ++p.x, ++p.y;

    if (p.x <= 0 || p.y <= 0)
    {
        p_Cmd.type = Util::UNKNOWN;
        std::cerr << "Error: Invalid Canvas Dimension {" <<p.x << ", " << p.y << "}" << endl;
        return;
    }
    p_Cmd.points.push_back(p);
}

void CommandParser::ReadCreateLineInput(Util::Command& p_Cmd)
{
    Point p = ReadTwoInteger(INPUT_START_POSITION_LINE);
    p_Cmd.points.push_back(p);
    p = ReadTwoInteger(INPUT_END_POSITION_LINE);
    p_Cmd.points.push_back(p);

    bool valid = (p_Cmd.points[0].x == p_Cmd.points[1].x) || (p_Cmd.points[0].y == p_Cmd.points[1].y);
    if (!valid)
    {
        p_Cmd.type = Util::UNKNOWN;
        std::cerr << "Error: line should be vertical or Horizontal" << endl;
        return;
    }

    // validate command
    if (p_Cmd.points[1] < p_Cmd.points[0])
    {
        Point temp = p_Cmd.points[1];
        p_Cmd.points[1] = p_Cmd.points[0];
        p_Cmd.points[0] = temp;
    }
}

void CommandParser::ReadCreateRectangleInput(Util::Command& p_Cmd)
{
    Point p = ReadTwoInteger(INPUT_LEFT_TOP_RECTANGLE);
    p_Cmd.points.push_back(p);
    p = ReadTwoInteger(INPUT_RIGHT_BOTTOM_RECTANGLE);
    p_Cmd.points.push_back(p);

    if (p_Cmd.points[0] < p_Cmd.points[1]) return;

    p_Cmd.type = Util::UNKNOWN;
    std::cerr << "Error: Cordinates LeftTop and Right Bottom shall be in order" << endl;
}

void CommandParser::ReadColorFillInput(Util::Command& p_Cmd)
{
    Point p = ReadTwoInteger(INPUT_POSITION_COLOR);
    p_Cmd.points.push_back(p);
    cout << "Enter color character\n>>> ";
    char color;
    cin >> color;
    p_Cmd.color = (int)color;
}

Util::Command CommandParser::ReadInputFromFileLine(const string& p_Line)
{
    Util::Command cmd;

    return cmd;
}

void CommandParser::DisplayMenu()
{
    cout << "                                                                                       \n\
    Command         Description                                                                     \n\
    C w h           Should create a new canvas of width w and height h.                             \n\
    L x1 y1 x2 y2   Should create a new line from (x1,y1) to (x2,y2).                               \n\
    R x1 y1 x2 y2   Should create a new rectangle, with upper left(x1,y1) and lower right(x2,y2).   \n\
    B x y c         Should fill the entire area connected to (x,y) with \"colour\" c.               \n\
    Q               Should quit the program." << endl;
    cout << ">>> ";
}

Point CommandParser::ReadTwoInteger(const string& p_Msg)
{
    cout << p_Msg << "\n>>> ";
    Point p;
    p.x = ReadIntegerFromTerminal() - 1;
    p.y = ReadIntegerFromTerminal() - 1;
    return p;
}
int CommandParser::ReadIntegerFromTerminal()
{
    int num;
    cin >> num;
    while  (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please Input Integer >>> ";
        cin >> num;
    }

    return num;
}
