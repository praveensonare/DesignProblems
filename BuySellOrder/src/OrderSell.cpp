#include "OrderSell.h"

void OrderSell::InsertOrder(const Order& p_Order)
{
    OrderBase::InsertOrder(p_Order);
    m_PriceIdsMap[p_Order.price].insert(p_Order.orderId);
    //m_TimePriceCacheMap[m_Orders[p_Order.orderId].timestamp.GetTime()]
    //cout << typeid(this).name() << "::" << __FUNCTION__ << "\t" << __LINE__ << endl;
    UpdateCacheMap(m_Orders[p_Order.orderId].timestamp.GetTime());
}

void OrderSell::AmendOrder(const Order& p_Order)
{
    double prevPrice = m_Orders[p_Order.orderId].price;
    m_PriceIdsMap[prevPrice].erase(p_Order.orderId);
    if (m_PriceIdsMap[prevPrice].empty())
    {
        m_PriceIdsMap.erase(prevPrice);
    }
    m_PriceIdsMap[p_Order.price].insert(p_Order.orderId);

    OrderBase::AmendOrder(p_Order);
    UpdateCacheMap(m_Orders[p_Order.orderId].timestamp.GetTime());
    //cout << typeid(this).name() << "::" << __FUNCTION__ << "\t" << __LINE__ << endl;
}

void OrderSell::CancelOrder(const Order& p_Order)
{
    double prevPrice = m_Orders[p_Order.orderId].price;
    m_PriceIdsMap[prevPrice].erase(p_Order.orderId);
    if (m_PriceIdsMap[prevPrice].empty())
    {
        m_PriceIdsMap.erase(prevPrice);
    }

    OrderBase::CancelOrder(p_Order);
    UpdateCacheMap(OrderTimestamp(p_Order.timestamp).GetTime());
}


//Finds the best SELL price and related order volume for a specific symbol at a given time.
PRICE_VOLUME OrderSell::GetBestSellAtTime(const string& p_Timestamp)
{
    if (m_TimePriceCacheMap.empty()) return {};

    if (m_TimePriceCacheMap.find(p_Timestamp) != m_TimePriceCacheMap.end())
    {
        return m_TimePriceCacheMap[p_Timestamp];
    }

    auto locate = [&](const string& timestamp)
    {
        map<string/*time*/, PRICE_VOLUME/*best sell price with volumes*/>::iterator it = m_TimePriceCacheMap.upper_bound(p_Timestamp);
        if (it == m_TimePriceCacheMap.end())
            return m_TimePriceCacheMap.rbegin()->second;
        else if (it == m_TimePriceCacheMap.begin())
            return PRICE_VOLUME();
        else
            return (--it)->second;
    };


    return locate(p_Timestamp);
}

void OrderSell::UpdateCacheMap(const string& p_Timestamp)
{
    map<double/*price*/, unordered_set<long long>/*Ids*/>::reverse_iterator it = m_PriceIdsMap.rbegin();
    vector<double> volumes;

    if (it != m_PriceIdsMap.rend())
    {
        for (const auto& id : it->second)
        {
            volumes.push_back(m_Orders[id].volume);
        }

        m_TimePriceCacheMap[p_Timestamp] = PRICE_VOLUME(it->first, volumes);
    }
}
//map<double/*price*/, unordered_set<long long>/*Ids*/> m_PriceIdsMap;
//unordered_map<string/*time*/, PRICE_VOLUME/*best sell price with volumes*/> m_TimePriceCacheMap;
