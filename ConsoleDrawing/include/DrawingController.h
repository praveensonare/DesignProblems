#include <unordered_map>
#include <string>
#include "ICanvas.h"
#include "CommandParser.h"
#include "CommandFactory.h"

using namespace std;

class CDrawingController
{
public:
    CDrawingController()
        : currInstanceIdx(0)
    {}

    void run(const string& p_File = string());

private:
    // reading input from console
    void ExecuteUserInputCommands();

    // reading inputs from file and processing all
    void ExecuteFileCommands(const string& p_FileName);

    unordered_map<int, ICanvas*> DrawingInstanceMap;
    int currInstanceIdx = 0;
    CommandParser m_Parser;
    CommandFactory m_CommandFactory;
};
