#ifndef ORDERSELL_H
#define ORDERSELL_H

#include "OrderBase.h"
#include <vector>

#define PRICE_VOLUME pair<double, vector<double>>

class OrderSell : public OrderBase
{
public:
    OrderSell(){}
    virtual ~OrderSell(){}
    void InsertOrder(const Order& p_Order);
    void AmendOrder(const Order& p_Order);
    void CancelOrder(const Order& p_Order);

    //Finds the best SELL price and related order volume for a specific symbol at a given time.
    PRICE_VOLUME GetBestSellAtTime(const string& p_Timestamp);

private:
    void UpdateCacheMap(const string& p_Timestamp);

    map<double/*price*/, unordered_set<long long>/*Ids*/> m_PriceIdsMap;
    map<string/*time*/, PRICE_VOLUME/*best sell price with volumes*/> m_TimePriceCacheMap;
};

#endif
