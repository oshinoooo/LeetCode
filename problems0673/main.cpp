#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int> &nums) {
        int n = nums.size();
        int maxLength = 0;
        int count = 0;

        vector<int> dp(n);
        vector<int> ct(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            ct[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        ct[i] = ct[j];
                    }
                    else if (dp[j] + 1 == dp[i]) {
                        ct[i] += ct[j];
                    }
                }
            }

            if (dp[i] > maxLength) {
                maxLength = dp[i];
                count = ct[i];
            }
            else if (dp[i] == maxLength) {
                count += ct[i];
            }
        }

        return count;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {2,2,2,2,2};
    cout << s.findNumberOfLIS(nums) << endl;
    cout << "--------------------" << endl;
    return 0;
}
