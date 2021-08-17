#pragma once

#include "OrderBuy.h"
#include "OrderSell.h"

#include <vector>

class OrderManager
{
public:
    explicit OrderManager(const string& p_File);
    ~OrderManager();

    //Counts the total number of orders per symbol.
    unordered_map<string, long long> OrderCounts(Utility::Side p_Side = Utility::ALL);

    //Finds the top 3 biggest BUY orders in terms of volume for a specific symbol.
    vector<pair<double, long long>> BiggestBuyOrders(const string& p_Symbol, int p_TopK = 3);

    //Finds the best SELL price and related order volume for a specific symbol at a given time.
    PRICE_VOLUME GetBestSellAtTime(const string& p_Symbol, const string& p_Timestamp);

    void ExecuteOrder(const Order& p_Order);
    vector<string> GetAllSymbols();
    void Status();

private:
    OrderBase* CreateOrder(Utility::Side p_Side);

    map<string/*symbol*/, map<Utility::Side, OrderBase*>> m_OrderBook;
    static std::once_flag readFile;
    string m_DataFile;
};
