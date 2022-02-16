#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        else if (n == 1)
            return nums[0];

        vector<int> dp = {nums[0], max(nums[0], nums[1])};
        for (int i = 2; i < n; ++i)
            dp.push_back(max(nums[i] + dp[i - 2], dp[i - 1]));
        return dp.back();
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {2, 1, 1, 2};
    cout << s.rob(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
