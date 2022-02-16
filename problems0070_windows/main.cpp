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
    int climbStairs1(int n) {
        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;

        vector<int> dp = {1, 2};
        int pre1 = 1;
        int pre2 = 2;
        int cur;
        for (int i = 2; i < n; ++i) {
            cur = pre1 + pre2;
            pre1 = pre2;
            pre2 = cur;
        }
        return cur;
    }

    int climbStairs2(int n) {
        vector<int> dp = {1, 2};
        for (int i = 2; i < n; ++i)
            dp.push_back(dp[i - 2] + dp[i - 1]);
        return dp[n - 1];
    }

    int climbStairs(int n) {
        vector<int> dp = {1, 2};
        for (int i = 2; i < n; ++i) {
            if ((i + 1) % 7 == 0)
                dp.push_back(0);
            else
                dp.push_back(dp[i - 2] + dp[i - 1]);
        }
        return dp[n - 1];
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.climbStairs(10) << endl;
    cout << "---------------------" << endl;
    return 0;
}
