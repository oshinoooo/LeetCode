#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (0 <= i - coins[j])
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }

        if (dp.back() == amount + 1)
            return -1;

        return dp.back();
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> coins = {2};
    int amount = 3;
    cout << s.coinChange(coins, amount) << endl;
    cout << "---------------------" << endl;
    return 0;
}
