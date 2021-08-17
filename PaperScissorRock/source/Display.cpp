#include "../include/Display.h"

SELECT_OPTION CDisplay::DisplayMenu()
{
    std::cout << std::endl;
    std::cout << "    ***********************" << std::endl;
    std::cout << "    * Selection MENU      *" << std::endl;
    std::cout << "    ***********************" << std::endl;
    std::cout << "    *  1. ROCK            *" << std::endl;
    std::cout << "    *  2. SCISSOR         *" << std::endl;
    std::cout << "    *  3. PAPER           *" << std::endl;
    std::cout << "    *  4. SHOW Stats      *" << std::endl;
    std::cout << "    *  5. Detailed Stats  *" << std::endl;
    std::cout << "    *  0. QUIT            *" << std::endl;
    std::cout << "    ***********************" << std::endl;

    std::string input;
    std::cout << "Your Input >> ";
    cin >> input;

    if (input.empty())
        return SELECT_OPTION::SELECT_MAX;

    unsigned option;
    SELECT_OPTION op = SELECT_OPTION::SELECT_MAX;
    try
    {
        option = std::stoi(input);
        if (option >= SELECT_OPTION::SELECT_MAX)
            op = SELECT_OPTION::SELECT_MAX;
        else
            op = static_cast<SELECT_OPTION>(option);
    }
    catch(std::invalid_argument e)
    {
        option = SELECT_OPTION::SELECT_MAX;
    }

    return op;
}

void CDisplay::ShowResult(RESULT p_Result, IPlayer* p_Player, IPlayer* p_Computer)
{
    std::cout << std::endl;
    ++m_Summary[0];
    switch(p_Result)
    {
        case RESULT::WIN:
            ++m_Summary[RESULT::WIN];
            std::cout << "Congratulations!!! You WIN" << std::endl;
        break;

        case RESULT::LOST:
            ++m_Summary[RESULT::LOST];
            std::cout << "Try Again!!! You LOST" << std::endl;
        break;

        case RESULT::DRAW:
            ++m_Summary[RESULT::DRAW];
            std::cout << "Try Again!!! Its a DRAW" << std::endl;
        break;

        default:
            std::cout << "Try Again!!! Technical Problem, Unable to determine Result" << std::endl;
        break;
    }
  
    if (p_Player && p_Computer)
    {
        const std::string& analysis = FormatString({std::to_string(m_Analysis.size()+1), 
                                                    GetResultInString(p_Result),
                                                    p_Player->GetSelection(), 
                                                    p_Computer->GetSelection()});
        m_Analysis.emplace_back(analysis);
        ShowAnalysis(m_Analysis.size() - 1);
    }
}

std::string CDisplay::GetTitle(std::string p_Title)
{
    std::string title = m_FrontPad;
    int offset = (CELL_WIDTH * 4)/2 - p_Title.length()/2;
    std::string pad = std::string(offset, ' ');
    title += pad + p_Title;
    return title;
}

std::string CDisplay::FormatString(const std::vector<std::string>& p_Strings)
{
    std::string delm = std::string(1, m_Delimeter);
    std::string brief = m_FrontPad + delm + " ";
    int pad = 0;
    for (auto s : p_Strings)
    {
        pad = STRING_WIDTH - s.length();
        brief += (pad > 0) ? s + std::string(pad, ' ') : s;
        brief += " " + delm + " ";
    }
    
    return brief;
}

std::string CDisplay::GetResultInString(RESULT p_Result)
{
    switch(p_Result)
    {
        case RESULT::WIN:
            return "WIN";
        break;

        case RESULT::LOST:
            return "LOST";
        break;

        case RESULT::DRAW:
            return "DRAW";
        break;

        default:
        break;
    }
    return std::string("INVALID");
}

void CDisplay::Summary()
{
    std::cout << GetTitle("SUMMARY") << std::endl;
    std::cout << m_FrontPad + m_DrawLine << std::endl;
    std::cout << FormatString({" #Game", "Win", "Lost", "Draw"}) << std::endl;
    std::cout << m_FrontPad + m_DrawLine << std::endl;
    vector<std::string> format;
    for (auto n : m_Summary) 
        format.emplace_back(std::to_string(n));

    std::cout << FormatString(format) << std::endl;
    std::cout << m_FrontPad + m_DrawLine << std::endl;
}

void CDisplay::ShowAnalysis(unsigned p_GameId)
{
    if (m_Analysis.empty())
    {
        std::cout << "Not Enough Games played for Detailed Analysis" << std::endl;
        return;
    }

    const std::string title = (p_GameId == UINT_MAX) ? GetTitle("GAME-ANALYSIS") : GetTitle("GAME - RESULT");

    std::cout << title << std::endl;
    std::cout << m_FrontPad + m_DrawLine << std::endl;
    std::string header = FormatString({"#Game", "Result", "You", "Computer"});
    std::cout << header << std::endl;
    std::cout << m_FrontPad + m_DrawLine << std::endl;

    if (p_GameId == UINT_MAX)
    {
        for (auto s : m_Analysis)
            std::cout << s << std::endl;
    }
    else
    {
        std::cout << m_Analysis[p_GameId] << std::endl;
    }
    std::cout << m_FrontPad + m_DrawLine << std::endl;

}

void CDisplay::ExitGame()
{
    cout << "\nThank You for Playing PAPER-SCISSOR-ROCK. Summary is below" << endl;
    Summary();
}
