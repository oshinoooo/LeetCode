#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        dp[0][0] = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            dp[i][0] = nums[i] + dp[i - 1][1];
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        }

        return max(dp.back()[0], dp.back()[1]);
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {2, 1, 1, 2};
    cout << s.rob(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
