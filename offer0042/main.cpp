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

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        vector<int> dp = {nums[0]};
        int max_sum = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            dp.push_back(max(dp[i - 1] + nums[i], nums[i]));
            max_sum = max(max_sum, dp.back());
        }
        return max_sum;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
