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
    string minNumber(vector<int>& nums)
    {
        vector<string> new_nums;
        for (auto num :nums)
            new_nums.push_back(to_string(num));

        quick_sort(new_nums, 0, nums.size() - 1);

        string out;
        for (auto num : new_nums)
            out += num;

        return out;
    }

private:
    void quick_sort(vector<string>& nums, int left, int right)
    {
        if (right <= left)
            return;

        string pivot = nums[left];

        int l = left;
        int r = right;
        while (l < r)
        {
            while (l < r && pivot + nums[r] <= nums[r] + pivot)
                --r;
            nums[l] = nums[r];

            while (l < r && nums[l] + pivot <= pivot + nums[l])
                ++l;
            nums[r] = nums[l];
        }
        nums[l] = pivot;

        quick_sort(nums, left, l - 1);
        quick_sort(nums, l + 1, right);
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1, 1, 1};
    cout << s.minNumber(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
