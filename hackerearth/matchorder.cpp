#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;


/*
 * Complete the 'matchOrders' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY orderList as parameter.
 */
struct order {
    int internalID;
    int id;
    string txntype;
    int qty;
    double price;
    string type;
    string status;
    int pending;
};
order getorder(string &orderlist, int &lastID) {
    stringstream ss(orderlist);
    string id;
    getline(ss, id, ' ');
    order current;
    current.internalID = lastID;
    lastID++;
    current.id = stoi(id);
    string qty;
    getline(ss, qty, ' ');
    current.qty = stoi(qty);
    getline(ss, current.txntype, ' ');
    string price;
    getline(ss, price, ' ');
    current.price = stod(price);
    getline(ss, current.type, ' ');
    current.pending = current.qty;
    return current;
}
vector<string> matchOrders(vector<string> orderList) {
    auto comp = [](order &a, order &b){
        return a.price == b.price? a.internalID > b.internalID: a.price > b.price;
    };
    priority_queue<order, vector<order>, decltype(comp)> buy(comp);
    priority_queue<order, vector<order>, decltype(comp)> sell(comp);
    int lastID = 0;
    string orders;

    for (auto orderlist: orderList) {
        order current = getorder(orderlist, lastID);
        if (current.txntype == "BUY") {
            buy.push(current);
        } else if (current.txntype == "SELL") {
            sell.push(current);
        }
    }
    vector<order> tempResult;
    while (!buy.empty() && !sell.empty()) {
        if (buy.top().price >= sell.top().price || buy.top().type == "MARKET" || sell.top().type == "MARKET") {
            auto buytop = buy.top();
            buy.pop();
            auto selltop = sell.top();
            sell.pop();
            int buyq = buytop.pending - selltop.pending;
            int sellq = selltop.pending - buytop.pending;
            buytop.pending = max(0, buyq);
            selltop.pending = max(0, sellq);
            if (buytop.pending != 0)
                buy.push(buytop);
            else
                tempResult.push_back(buytop);
            if (selltop.pending != 0)
                sell.push(selltop);
            else 
                tempResult.push_back(selltop);
        } else {
            tempResult.push_back(sell.top());
            sell.pop();
        }
    }
    while(!sell.empty()) {
        tempResult.push_back(sell.top());
        sell.pop();
    }
    while (!buy.empty()) {
        tempResult.push_back(buy.top());
        buy.pop();
    }
    sort(tempResult.begin(), tempResult.end(), [](order &a, order &b){return a.internalID < b.internalID;});
    vector<string> result;
    for (auto res: tempResult) {
        if (res.pending == 0)
            result.push_back(to_string(res.id) + " " + res.txntype + " EXECUTED " + to_string(res.qty) + " " + to_string(res.qty));
        else if (res.pending == res.qty)
            result.push_back(to_string(res.id) + " " + res.txntype + " PENDING " + to_string(res.qty) + " 0");
        else 
            result.push_back(to_string(res.id) + " " + res.txntype + " PARTIALLY_EXECUTED " + to_string(res.qty) + " " + to_string(res.qty - res.pending));
    }
    return result;
}

int main()
{
    
    vector<string> orderList;

    orderList.push_back("1 10 BUY 100.0 LIMIT");
    orderList.push_back("2 5 SELL 100.0 LIMIT");
    orderList.push_back("3 5 SELL 99.90 LIMIT");
    orderList.push_back("4 5 SELL 100.0 LIMIT");

    vector<string> result = matchOrders(orderList);
    for (auto res: result)
        cout << res << endl;
    return 0;
}
