#include "OrderManager.h"
#include "Utility.h"

OrderManager* ORDER_MANAGER = nullptr;
vector<string> symbols;

void test_OrderCounts();
void test_BiggestBuyOrders();
void test_GetBestSellAtTime();

int main(int argc, char *argv[]){

    if (argc < 2)
    {
        cout << "Usage - \n Provide .dat filename as argument" << endl;
        return 0;
    }

    const char* filename = argv[1];

    ORDER_MANAGER = new OrderManager(filename);
    symbols = (ORDER_MANAGER) ? ORDER_MANAGER->GetAllSymbols() : vector<string>();

    test_OrderCounts();

    test_BiggestBuyOrders();

    test_GetBestSellAtTime();

    if (ORDER_MANAGER)
    {
        delete ORDER_MANAGER;
        ORDER_MANAGER = nullptr;
    }

    cout << "filename : " << filename << endl;
    return 0;
}

void test_OrderCounts()
{
    if (!ORDER_MANAGER) return;

    cout << "\n**** - OrderCounts - ****" << endl;
    cout << "[SYMBOL]\t[ORDER-COUNT]" << endl;
    unordered_map<string, long long> symbolOrderIdMap = ORDER_MANAGER->OrderCounts();
    for (const auto& order : symbolOrderIdMap)  cout << order.first << "\t\t" << order.second << endl;
}

void test_BiggestBuyOrders()
{
    if (!ORDER_MANAGER) return;

    int topK = 3;
    cout << "\n**** - BiggestBuyOrders - ****" << endl;
    cout << "[SYMBOL]\t[TOP-"<< topK << "]" << endl;
    for (const auto& symbol : symbols)
    {
        vector<pair<double, long long>> bestBuy = ORDER_MANAGER->BiggestBuyOrders(symbol, topK);
        cout << symbol << "\t\t{";
        for (auto n : bestBuy) cout << n.first << " ";
        cout << "}" << endl;
    }
}

void test_GetBestSellAtTime()
{
    if (!ORDER_MANAGER) return;

    vector<string> timestamp= {"09:00:00", "09:00:23", "13:11:59",
                               "15:48:58", "15:48:59", "16:11:59"};

    cout << "\n**** - GetBestSellAtTime - ****" << endl;
    cout << "[SYMBOL]\t[TIMESTAMP]\t[PRICE]\t[VOLUME...]" << endl;
    for (int pos = 0; pos < timestamp.size(); ++pos)
    {
        for (auto symbol : symbols)
        {
            PRICE_VOLUME bestSell = ORDER_MANAGER->GetBestSellAtTime(symbol, timestamp[pos]);
            cout << symbol << "\t\t"<< timestamp[pos] << "\t" << bestSell.first <<"\t{";
            for (auto v : bestSell.second) cout << v << " ";
            cout << "}"<< endl;
        }
    }
}
