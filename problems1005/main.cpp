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
    int largestSumAfterKNegations(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < 0 && 0 < k)
            {
                nums[i] = -nums[i];
                --k;
            }
            else
                break;
        }

        sort(nums.begin(), nums.end());

        if (k % 2)
            nums[0] = -nums[0];

        int max_sum = 0;
        for (auto& num : nums)
            max_sum += num;

        return max_sum;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {2,-3,-1,5,-4};
    int k = 2;
    cout << s.largestSumAfterKNegations(nums, k) << endl;
    cout << "---------------------" << endl;
    return 0;
}
