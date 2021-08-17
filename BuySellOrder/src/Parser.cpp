#include "Parser.h"

Order Parser::CreateOrderFromFileEntry(const string &p_OrderStr)
{
    size_t startPos = 0;
    size_t pos = p_OrderStr.find_first_of(';');
    const string timestamp = p_OrderStr.substr(startPos, pos);

    startPos += timestamp.length() + 1;
    pos = p_OrderStr.find_first_of(';', pos+1);
    const string symbol = p_OrderStr.substr(startPos, pos - startPos);

    startPos += symbol.length() + 1;
    pos = p_OrderStr.find_first_of(';', pos+1);
    const string orderIdStr = p_OrderStr.substr(startPos, pos - startPos);
    const long long orderId = std::stoll(orderIdStr);

    startPos += orderIdStr.length() + 1;
    pos = p_OrderStr.find_first_of(';', pos+1);
    const string opStr = p_OrderStr.substr(startPos, pos - startPos);
    const Utility::Operation op = Utility::GetOperationFromString(opStr);

    startPos += opStr.length() + 1;
    pos = p_OrderStr.find_first_of(';', pos+1);
    const string sideStr = p_OrderStr.substr(startPos, pos - startPos);
    const Utility::Side side = Utility::GetSideFromString(sideStr);

    startPos += sideStr.length() + 1;
    pos = p_OrderStr.find_first_of(';', pos+1);
    const string volumeStr = p_OrderStr.substr(startPos, pos - startPos);
    const double volume = std::stod(volumeStr);


    startPos += volumeStr.length() + 1;
    pos = p_OrderStr.find_first_of(';', pos+1);
    const string priceStr = p_OrderStr.substr(startPos, pos - startPos);
    const double price = std::stod(priceStr);

    return Order(timestamp, symbol, orderId, op, side, volume, price);
}
