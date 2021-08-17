#include <fstream>
#include <mutex>
#include <iostream>
#include "Canvas.h"

#include "DrawingController.h"
#include "DisplayCanvas.h"

using namespace std;

void CDrawingController::ExecuteUserInputCommands()
{
    while(true)
    {
        Util::Command userCmd = m_Parser.ReadInputFromUser();
        ICommand *cmd = m_CommandFactory.CreateCommandObj(userCmd);
        if (cmd)
        {
            cmd->Execute();
            DisplayCanvasToConsole::Display();
        }
        else
            cout << "check input format" << endl;
    }
}

// reading inputs from file and processing all
void CDrawingController::ExecuteFileCommands(const string& p_FileName)
{
    try {
        fstream datFile;
        datFile.open(p_FileName, ios::in);

        if (datFile.is_open())
        {
            string line;
            while(getline(datFile, line))
            {
                cout << "TODO: " << line << endl;
            }

            datFile.close();
        }
        else
        {
            throw std::exception();
        }
    }
    catch (...)
    {
        std::cerr << "Exception opening/reading/closing file\n";
    }
}

void CDrawingController::run(const string& p_File /*=string()*/)
{
    if (p_File.empty())
    {
        ExecuteUserInputCommands();
    }
    else
    {
        ExecuteFileCommands(p_File);
    }
}

