#pragma once

#include <iostream>
#include <vector>
#include <climits>

#include "../include/UserDefined.h"
#include "../include/IPlayer.h"

#define CELL_WIDTH   11
#define STRING_WIDTH 8
#define PAD_FRONT 4
using namespace std;

class CDisplay
{
private:
    std::vector<std::string> m_Analysis;
    std::vector<int> m_Summary = {0, 0, 0, 0}; // #games, win, lost, draw
    std::string m_FrontPad = std::string(PAD_FRONT, ' ');
    char m_Delimeter = '*';
    std::string m_DrawLine = std::string(CELL_WIDTH * 4 + 1, m_Delimeter);
  
    std::string GetTitle(std::string p_Title);
    std::string GetResultInString(RESULT p_Result);
    std::string FormatString(const std::vector<std::string>& p_Strings);
public:
    CDisplay() {}
    ~CDisplay() {}

    SELECT_OPTION DisplayMenu();
    void ShowResult(RESULT p_Result, IPlayer* p_Player, IPlayer* p_Computer);
    void Summary();
    void ShowAnalysis(unsigned p_GameId = UINT_MAX);
    void ExitGame();

};
