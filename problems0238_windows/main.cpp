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
    vector<int> productExceptSelf1(vector<int>& nums)
    {
        vector<int> left = {1};
        for (int i = 0; i < nums.size() - 1; ++i)
            left.push_back(left.back() * nums[i]);

        vector<int> right = {1};
        for (int i = nums.size() - 1; 0 < i; --i)
            right.push_back(right.back() * nums[i]);

        vector<int> out;
        for (int i = 0; i < left.size(); ++i)
            out.push_back(left[i] * right[right.size() - i - 1]);
        return out;
    }

    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> out = {1};
        for (int i = 0; i < nums.size() - 1; ++i)
            out.push_back(out.back() * nums[i]);

        int tmp = 1;
        for (int i = nums.size() - 1; 0 < i; --i)
        {
            tmp *= nums[i];
            out[i - 1] *= tmp;
        }

        return out;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1,2,3,4};
    vector<int> out = s.productExceptSelf(nums);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
