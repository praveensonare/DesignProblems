#include "OrderBuy.h"

void OrderBuy::InsertOrder(const Order& p_Order)
{
    m_VolumeIdsMap[p_Order.volume].insert(p_Order.orderId);
    OrderBase::InsertOrder(p_Order);
    //cout << typeid(this).name() << "::" << __FUNCTION__ << "\t" << __LINE__ << endl;
}

void OrderBuy::AmendOrder(const Order& p_Order)
{
    double prevVolume = m_Orders[p_Order.orderId].volume;
    m_VolumeIdsMap[prevVolume].erase(p_Order.orderId);
    if (m_VolumeIdsMap[prevVolume].empty())
    {
        m_VolumeIdsMap.erase(prevVolume);
    }
    m_VolumeIdsMap[p_Order.volume].insert(p_Order.orderId);

    OrderBase::AmendOrder(p_Order);
    //cout << typeid(this).name() << "::" << __FUNCTION__ << "\t" << __LINE__ << endl;
}

void OrderBuy::CancelOrder(const Order& p_Order)
{
    double prevVolume = m_Orders[p_Order.orderId].volume;
    m_VolumeIdsMap[prevVolume].erase(p_Order.orderId);
    if (m_VolumeIdsMap[prevVolume].empty())
    {
        m_VolumeIdsMap.erase(prevVolume);
    }

    OrderBase::CancelOrder(p_Order);
    //cout << typeid(this).name() << "::" << __FUNCTION__ << "\t" << __LINE__ << endl;
}

vector<pair<double, long long>> OrderBuy::BiggestBuyOrders(int p_TopK/* = 3*/)
{
    vector<pair<double, long long>> result;
    map<double/*volume*/, unordered_set<long long>/*Ids*/>::reverse_iterator it;
    for (it = m_VolumeIdsMap.rbegin(); it != m_VolumeIdsMap.rend() && p_TopK > 0; ++it)
    {
        for (const auto n : it->second)
        {
            if (p_TopK <= 0) return result;

            result.push_back(pair<double, long long>(it->first, n));
            --p_TopK;
        }
    }

    return result;
}
