#pragma once

#include "Display.h"
#include "iostream"
#include "Canvas.h"
#include "CanvasManager.h"

class DisplayCanvasToConsole : public IDisplay
{
public:
    static void Display()
    {
        Canvas* canvas = dynamic_cast<Canvas*>(CanvasManager::GetInstance()->GetCanvasInFocus()); // get here using singleton
        if (!canvas) return;

        const vector<vector<char>>& mat = canvas->GetCanvasView();
        if (mat.empty()) return;

        unsigned width = mat[0].size();
        cout << "H = " << mat.size() << " W = " << mat[0].size() << endl;
        for (unsigned x = 0; x < width+2; ++x) cout << "-";
        cout << endl;


        for (unsigned y = 0; y < mat.size(); ++y)
        {
            cout << "|";
            for (unsigned x = 0; x < width; ++x)
            {
                cout << mat[y][x] ;
            }
            cout << "|" << endl;
        }

        for (unsigned x = 0; x < width+2; ++x) cout << "-";
        cout << endl;
    }
};
