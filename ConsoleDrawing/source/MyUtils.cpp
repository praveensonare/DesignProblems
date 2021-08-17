#include "MyUtils.h"
#include <map>

using namespace Util;

CommandType Util::CommandTypeFromChar(const char ch)
{
    static map<char, CommandType> cmdTypeMap{{'C', CREATE_CANVAS},
                                             {'c', CREATE_CANVAS},
                                             {'L', CREATE_LINE},
                                             {'l', CREATE_LINE},
                                             {'R', CREATE_RECTANGLE},
                                             {'r', CREATE_RECTANGLE},
                                             {'B', COLOR_FILL},
                                             {'b', COLOR_FILL},
                                             {'Q', QUIT},
                                             {'q', QUIT},
                                             {'1', ALL_CANVAS_DISPLAY},
                                             {'2', SELECT_CANVAS},
                                             {'3', DELETE},
                                             {'3', UNDO},
                                             {'5', REDO}
                                            };

    return (cmdTypeMap.find(ch) == cmdTypeMap.end()) ? UNKNOWN : cmdTypeMap[ch];
}

int Util::bound(int val, int low, int high)
{
    return min(max(val, low), high);
}
