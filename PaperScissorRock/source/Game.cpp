#include "../include/Game.h"

#include<iostream>

#include "../include/ComputerPlayer.h"
#include "../include/Display.h"

CGame::CGame()
{
}

CGame::~CGame()
{
    if (m_Player) delete m_Player;
    if (m_Computer) delete m_Computer;
    m_Computer = m_Player = nullptr;
}

void CGame::Init()
{
    m_Player = new CPlayer();
    m_Computer = new CComputerPlayer();
}

void CGame::Play()
{
    Init();

    SELECT_OPTION userSelection = SELECT_OPTION::SELECT_MAX;
    RESULT result = RESULT::RESULT_UNDEFINED; 
    while (true)
    {
        userSelection = m_Display.DisplayMenu();
        switch(userSelection)
        {
            case SELECT_OPTION::SELECT_QUIT:
                m_Display.ExitGame();
                return;

            case SELECT_OPTION::SELECT_ROCK:
            case SELECT_OPTION::SELECT_SCISSOR:
            case SELECT_OPTION::SELECT_PAPER:
                m_Player->SetSelectedObject(userSelection);
                m_Computer->SetSelectedObject();

                result = m_Player->PlayMatch(m_Computer);
                m_Display.ShowResult(result, m_Player, m_Computer);
                break;

            case SELECT_OPTION::SELECT_GAMES_SUMMARY:
                m_Display.Summary();
                break;

            case SELECT_OPTION::SELECT_GAMES_ANALYSIS:
                m_Display.ShowAnalysis();
                break;

            default:
                cout << "\n*** Invalid Input! ("<< userSelection <<"). Select from  Menu!! ***" <<endl;
                break;
        }
    }
}

