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
    int maxProfit(vector<int>& prices) {
        stack<int> stk;
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (auto& price : prices) {
            maxProfit = max(maxProfit, price - minPrice);
            minPrice = min(minPrice, price);
        }
        return maxProfit;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    cout << s.maxProfit(prices) << endl;
    cout << "---------------------" << endl;
    return 0;
}
