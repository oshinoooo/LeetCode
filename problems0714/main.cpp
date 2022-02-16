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
#include <ctime>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int totalProfit = 0;
        int buy = prices[0] + fee;

        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < buy - fee)
                buy = prices[i] + fee;
            else if (buy < prices[i]) {
                totalProfit += prices[i] - buy;
                buy = prices[i];
            }
        }

        return totalProfit;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << s.maxProfit(prices, fee) << endl;
    cout << "---------------------" << endl;
    return 0;
}
