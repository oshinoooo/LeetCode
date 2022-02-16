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
    int rob(vector<int>& nums)
    {
        vector<int> dp = {0, 0};
        for (int i = 0; i < nums.size(); ++i)
            dp.push_back(max(dp[i] + nums[i], dp[i + 1]));
        return dp.back();
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << s.rob(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
