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
    int lengthOfLIS1(vector<int>& nums) {
        int size = nums.size();
        int maxLength = 1;

        vector<int> dp(size, 1);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }

    int lengthOfLIS2(vector<int>& nums) {
        vector<int> dp = {nums[0]};

        for (int i = 1; i < nums.size(); ++i) {
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

    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int length = 1;

        for (int i = 1; i < nums.size(); ++i) {
            int head = 0;
            int tail = length - 1;

            while(head <= tail) {
                int mid = (head + tail) / 2;
                if(dp[mid] < nums[i])
                    head = mid + 1;
                else
                    tail = mid - 1;
            }

            dp[head] = nums[i];
            if (head == length)
                ++length;
        }

        return length;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1,3,6,7,9,4,10,5,6};
    cout << s.lengthOfLIS(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
