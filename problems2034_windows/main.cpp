#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cctype>
#include <numeric>
#include <math.h>

using namespace std;

class StockPrice {
public:
    void update(int timestamp, int price) {
        if (datePrices.count(timestamp)) {
            prices.erase({datePrices[timestamp], timestamp});
            datePrices.erase(timestamp);
        }

        prices.emplace(price,timestamp);
        datePrices.emplace(timestamp, price);
    }

    int current() {
        return datePrices.rbegin()->second;
    }

    int maximum() {
        return prices.rbegin()->first;
    }

    int minimum() {
        return prices.begin()->first;
    }

private:
    map<int, int> datePrices;
    set<pair<int, int>> prices;
};

int main() {
    cout << "---------------------" << endl;
    StockPrice stockPrice;
    stockPrice.update(1, 10);
    stockPrice.update(2, 5);
    cout << stockPrice.current() << endl;
    cout << stockPrice.maximum() << endl;

    stockPrice.update(1, 3);
    cout << stockPrice.maximum() << endl;

    stockPrice.update(4, 2);
    cout << stockPrice.minimum() << endl;
    cout << "---------------------" << endl;
    return 0;
}
