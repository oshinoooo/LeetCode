#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int rob(vector<int>& nums)
    {
        int length = nums.size();
        if (length == 1)
            return nums[0];
        else if (length == 2)
            return max(nums[0], nums[1]);
        int first = rob_with_range(nums, 0, length - 2);
        int last  = rob_with_range(nums, 1, length - 1);
        return max(first, last);
    }

private:
    int rob_with_range(vector<int>& nums, int start, int end)
    {
        vector<int> dp = {nums[start], max(nums[start], nums[start + 1])};
        for (int i = start + 2; i <= end; i++)
            dp.push_back(max(nums[i] + dp[i - start - 2], dp[i - start - 1]));
        return dp.back();
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    cout << s.rob(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
