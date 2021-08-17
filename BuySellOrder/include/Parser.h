#ifndef PARSER_H
#define PARSER_H
#include "Order.h"

class Parser
{
public:
    Parser(){};

    static Order CreateOrderFromFileEntry(const string& p_OrderStr);
};

#endif
