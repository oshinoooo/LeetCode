#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int steal;
    int noSteal;
    vector<int> stealPath;
    vector<int> noStealPath;
    node() : steal(0), noSteal(0) {}
};

class Solution {
public:
    int rob1(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        dp[0][0] = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            dp[i][0] = nums[i] + dp[i - 1][1];
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        }

        return max(dp.back()[0], dp.back()[1]);
    }

    int rob(vector<int>& nums) {
        vector<node> dp(nums.size());
        dp[0].steal = nums[0];
        dp[0].stealPath = {0};

        for (int i = 1; i < nums.size(); ++i) {
            node tmp = dp[i - 1];

            dp[i].steal = nums[i] + tmp.noSteal;
            dp[i].stealPath = tmp.noStealPath;
            dp[i].stealPath.push_back(i);

            dp[i].noSteal = max(tmp.steal, tmp.noSteal);
            if (tmp.steal < tmp.noSteal)
                dp[i].noStealPath = tmp.noStealPath;
            else
                dp[i].noStealPath = tmp.stealPath;
        }

        vector<int> tmp;
        if (dp.back().steal < dp.back().noSteal)
            tmp = dp.back().noStealPath;
        else
            tmp = dp.back().stealPath;

        for (int num : tmp)
            cout << num <<" ";
        cout << endl;

        return max(dp.back().steal, dp.back().noSteal);
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
