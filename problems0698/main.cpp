#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution
{
public:
    bool canPartitionKSubsets1(vector<int>& nums, int k)
    {
        int sum = accumulate(nums.begin(),nums.end(), 0);

        if (sum % k != 0)
            return false;

        int target = sum / k;

        sort(nums.begin(), nums.end(), greater<int>());

        if (nums[nums.size() - 1] > target)
            return false;

        vector<int> vis (nums.size(), 0);
        for(int i = 0; i < nums.size(); ++i)
        {
            if(vis[i] != 0)
                continue;

            if(!dfs(i+1,target-nums[i],vis,nums))
                return false;
        }

        return true;
    }

    bool dfs(int beg, int target, vector<int>&vis, vector<int>&nums)
    {
        if(target == 0)
            return true;
        if(beg == nums.size())
            return false;

        for(int i = beg; i < nums.size(); ++i)
        {
            if(vis[i])
                continue;

            if(nums[i] > target)
                continue;

            vis[i] = 1;
            if(dfs(i+1, target-nums[i], vis, nums))
                return true;
            else
                vis[i] = 0;
        }
        return false;
    }
};

int main()
{
    cout << "---------------" << endl;
    Solution s;
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;
    cout << s.canPartitionKSubsets1(nums, k) << endl;
    cout << "---------------" << endl;
    return 0;
}
