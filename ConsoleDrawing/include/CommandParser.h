#pragma once

#include "MyUtils.h"
#include <string>

#define INPUT_CANVAS_DIMENTION          "Input Dimension of Canvas {WIDTH, HEIGHT}"
#define INPUT_POSITION_COLOR            "Input Position to Color {x, y}"
#define INPUT_LEFT_TOP_RECTANGLE        "Input Left Top Position of Rectangle {x1, y1}"
#define INPUT_RIGHT_BOTTOM_RECTANGLE    "Input Right Bottom Position of Rectangle {x2, y2}"
#define INPUT_START_POSITION_LINE       "Input Start Position of Line {x1, y1}"
#define INPUT_END_POSITION_LINE         "Input End Position of Line {x2, y2}"

class CommandParser
{
public:
    Util::Command ReadInputFromUser();
    Util::Command ReadInputFromFileLine(const string& p_Line);

private:
    void DisplayMenu();
    void ReadCreateCanvasInput(Util::Command& p_Cmd);
    void ReadCreateLineInput(Util::Command& p_Cmd);
    void ReadCreateRectangleInput(Util::Command& p_Cmd);
    void ReadColorFillInput(Util::Command& p_Cmd);
    Point ReadTwoInteger(const string& p_Msg);
    int ReadIntegerFromTerminal();
};
