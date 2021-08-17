#include "OrderManager.h"
#include "Parser.h"

std::once_flag OrderManager::readFile;

OrderManager::OrderManager(const string& p_File) : m_DataFile(p_File)
{
    call_once(readFile, [&](){
        try {
            fstream datFile;
            datFile.open(m_DataFile, ios::in);

            if (datFile.is_open()){
                string line;
                while(getline(datFile, line))
                {
                    Order order = Parser::CreateOrderFromFileEntry(line);
                    //order.Display();
                    ExecuteOrder(order);
                    //Status();
                }

              datFile.close();
              //Status();
            }
            else
            {
                throw std::exception();
            }
        }
        catch (...) {
                std::cerr << "Exception opening/reading/closing file\n";
        }
    });
}

OrderManager::~OrderManager()
{
    //map<string/*symbol*/, map<Utility::Side, OrderBase*>> m_OrderBook;
    for (const auto& orderMap : m_OrderBook)
    {
        for (const auto& order : orderMap.second)
        {
            if (order.second) delete order.second;
        }
    }
}

void OrderManager::ExecuteOrder(const Order& p_Order)
{
    switch (p_Order.op)
    {
        case Utility::INSERT:
            if (!m_OrderBook[p_Order.symbol][p_Order.side])
            {
                m_OrderBook[p_Order.symbol][p_Order.side] = CreateOrder(p_Order.side);
            }
            m_OrderBook[p_Order.symbol][p_Order.side]->InsertOrder(p_Order);
        break;

        case Utility::AMEND:
            if (m_OrderBook[p_Order.symbol][p_Order.side])
            {
                m_OrderBook[p_Order.symbol][p_Order.side]->AmendOrder(p_Order);
            }
        break;

        case Utility::CANCEL:
            //m_OrderIds.erase(p_Order.orderId);
            if (m_OrderBook[p_Order.symbol][p_Order.side])
            {
                m_OrderBook[p_Order.symbol][p_Order.side]->CancelOrder(p_Order);
                if (m_OrderBook[p_Order.symbol][p_Order.side]->GetTotalOrders() == 0)
                {
                    //delete m_OrderBook[p_Order.symbol][p_Order.side];
                    //m_OrderBook[p_Order.symbol][p_Order.side] = nullptr;
                }
            }
        break;

        default:
        break;
    }
}

OrderBase* OrderManager::CreateOrder(Utility::Side p_Side)
{
    OrderBase* order = nullptr;
    if (p_Side == Utility::BUY)
        order = new OrderBuy();
    else
        order = new OrderSell();

    return order;
}

//Counts the total number of orders per symbol.
unordered_map<string, long long> OrderManager::OrderCounts(Utility::Side p_Side/* = Utility::ALL*/)
{
    unordered_map<string, long long> result;

    auto GetTotalOrderPerSymbol = [&](map<Utility::Side, OrderBase*> orderMap)
    {
        int totalOrder = 0;
        for (const auto& order : orderMap)
        {
            if ((p_Side == Utility::ALL || p_Side == order.first) && (order.second))
                totalOrder += order.second->GetTotalOrders();
        }
        return totalOrder;
    };

    long long orderCount;
    for (const auto& orderSymbol : m_OrderBook)
    {
        orderCount = GetTotalOrderPerSymbol(orderSymbol.second);
        if (orderCount != 0)
            result[orderSymbol.first] = orderCount;
    }

    return result;
}

//Finds the top 3 biggest BUY orders in terms of volume for a specific symbol.
vector<pair<double, long long>> OrderManager::BiggestBuyOrders(const string& p_Symbol, int p_TopK)
{
    vector<pair<double, long long>> result;
    OrderBuy* orderBuy = dynamic_cast<OrderBuy*>(m_OrderBook[p_Symbol][Utility::BUY]);
    if (orderBuy)
    {
        result = orderBuy->BiggestBuyOrders(p_TopK);
    }

    return result;
}

//Finds the best SELL price and related order volume for a specific symbol at a given time.
PRICE_VOLUME OrderManager::GetBestSellAtTime(const string& p_Symbol, const string& p_Timestamp)
{
    PRICE_VOLUME result;
    OrderSell* orderSell = dynamic_cast<OrderSell*>(m_OrderBook[p_Symbol][Utility::SELL]);
    if (orderSell)
    {
        result = orderSell->GetBestSellAtTime(p_Timestamp);
    }
    return result;
}

vector<string> OrderManager::GetAllSymbols()
{
    vector<string> symbols;
    for (const auto& sym : m_OrderBook)
    {
        symbols.push_back(sym.first);
    }
    return symbols;
}
void OrderManager::Status()
{
    cout << "++++++++++++++++++++++++++++++++++++++++++++++\nStatus" << endl;
    for (auto ob : m_OrderBook)
    {
        cout << "[" << ob.first << "]" << endl;// << ob.second[Utility::BUY]->GetOrderCount() << " " << ob.second[Utility::SELL]->GetOrderCount() << endl;
        if (ob.second[Utility::BUY])
        {
            cout << "\tBUY\t";
            ob.second[Utility::BUY]->Status();
        }
        if (ob.second[Utility::SELL])
        {
            cout << "\tSELL\t";
            ob.second[Utility::SELL]->Status();
        }
    }
    cout << "++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
}
