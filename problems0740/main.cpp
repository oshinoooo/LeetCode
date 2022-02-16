#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
public:
    int deleteAndEarn(vector<int>& nums)
    {
        map<int, int> sums;
        for (int i = 0; i < nums.size(); ++i)
            ++sums[nums[i]];

        if (sums.size() == 0)
            return 0;
        else if (sums.size() == 1)
            return sums.begin()->first * sums.begin()->second;

        vector<int> points;
        map<int, int>::iterator it = sums.begin();
        for (int i = 0; i <= sums.rbegin()->first; ++i)
        {
            if (sums.count(i))
            {
                points.push_back(it->first * it->second);
                ++it;
            }
            else
                points.push_back(0);
        }

        vector<int> dp = {points[0], max(points[0], points[1])};
        for (int i = 2; i < points.size(); ++i)
            dp.push_back(max(dp[i - 2] + points[i], dp[i - 1]));
        return dp.back();
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {3, 1};
    cout << s.deleteAndEarn(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
