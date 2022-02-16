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
    int maxProduct(vector<int>& nums)
    {
        vector <int> max_mul = {nums[0]};
        vector <int> min_mul = {nums[0]};
        for (int i = 1; i < nums.size(); ++i)
        {
            max_mul.push_back(max(max_mul.back() * nums[i], min_mul.back() * nums[i]));
//            maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
//            minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
        }
        return *max_element(maxF.begin(), maxF.end());
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {2, 3, -2, 4};
    cout << s.maxProduct(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
