#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS1(vector<int>& nums) {
        vector<int> tmp = {INT_MIN};
        return myLengthOfLIS(nums, tmp, 0);
    }

    int myLengthOfLIS(const vector<int>& nums, vector<int>& tmp, int index) {
        int n = nums.size();

        if (n <= index)
            return tmp.size() - 1;

        int maxLength = tmp.size() - 1;

        for (int i = index; i < n; ++i) {
            if (tmp.back() < nums[i]) {
                tmp.push_back(nums[i]);
                maxLength = max(maxLength, myLengthOfLIS(nums, tmp, i + 1));
                tmp.pop_back();
            }
        }

        return maxLength;
    }

    int lengthOfLIS2(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 1;

        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }

    int lengthOfLIS3(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp = {nums[0]};

        for (int i = 1; i < n; ++i) {
            if (dp.back() < nums[i])
                dp.push_back(nums[i]);
            else {
                for (int j = 0; j < dp.size(); ++j) {
                    if (nums[i] <= dp[j]) {
                        dp[j] = nums[i];
                        break;
                    }
                }
            }
        }

        return dp.size();
    }

    int lengthOfLIS4(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp = {nums[0]};

        for (int i = 1; i < n; ++i) {
            if (dp.back() < nums[i])
                dp.push_back(nums[i]);
            else {
                int head = 0;
                int tail = dp.size() - 1;

                while (head <= tail) {
                    int mid = (head + tail) / 2;

                    if (nums[i] <= dp[mid])
                        tail = mid - 1;
                    else
                        head = mid + 1;
                }
                dp[head] = nums[i];
            }
        }

        return dp.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;
        vector<int> dp(n, 1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {0,1,0,3,2,3};
    cout << s.lengthOfLIS(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}