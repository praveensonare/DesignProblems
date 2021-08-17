#pragma once

#include <vector>

#include "../include/IPlayer.h"
#include "../include/Display.h"

using namespace std;

class CGame
{
private:
    IPlayer* m_Player;    
    IPlayer* m_Computer;  
    CDisplay m_Display;

public:
    CGame();
    ~CGame();

    void Init();
    void Play();
};
