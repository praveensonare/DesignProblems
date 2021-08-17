#include "../include/Paper.h"

CPaper::CPaper()
{
    m_Type = SELECT_OPTION::SELECT_PAPER;
}

CPaper::~CPaper()
{

}

RESULT CPaper::FindWinner(IPlayObject* p_CompObject)
{
    if (!p_CompObject) return RESULT::RESULT_UNDEFINED;

    RESULT result = RESULT::RESULT_UNDEFINED;
    switch(p_CompObject->m_Type)
    {
        case SELECT_OPTION::SELECT_ROCK:
            result = RESULT::WIN;
            break;
        case SELECT_OPTION::SELECT_SCISSOR:
            result = RESULT::LOST;
            break;
        case SELECT_OPTION::SELECT_PAPER:
            result = RESULT::DRAW;
            break;
        default:
            result = RESULT::RESULT_UNDEFINED;
            break;
    }
    return result;
}
