#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maxProfit1(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (auto& price : prices) {
            maxProfit = max(maxProfit, price - minPrice);
            minPrice = min(minPrice, price);
        }
        return maxProfit;
    }

    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            maxProfit = max(maxProfit, price - minPrice);
            minPrice = min(minPrice, price);
        }

        return maxProfit;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(prices) << endl;
    cout << "---------------------" << endl;
    return 0;
}
