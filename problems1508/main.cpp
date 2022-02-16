#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <numeric>

using namespace std;

class Solution
{
public:
    int rangeSum(vector<int>& nums, int n, int left, int right)
    {
        vector<int> sums;
        for (int i = 0; i < n; ++i)
        {
            int sum = 0;
            for (int j = i; j < n; ++j)
            {
                sum = (sum + nums[j]) % 1000000007;
                sums.push_back(sum);
            }
        }
        sort(sums.begin(), sums.end());
        int ans = 0;
        for (int i = left - 1; i < right; i++)
            ans = (ans + sums[i]) % 1000000007;
        return ans;
    }
};

int main()
{
    cout << "------------------" << endl;
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    int n = 4;
    int left = 1;
    int right = 5;
    cout << s.rangeSum(nums, n, left, right) << endl;
    cout << "------------------" << endl;
    return 0;
}