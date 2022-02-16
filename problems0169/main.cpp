#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int majorityElement1(vector<int>& nums)
    {
        if (nums.size() < 3)
            return nums[0];

        map<int, int> m;
        for (auto num : nums)
        {
            ++m[num];
            if (m[num] > nums.size() / 2)
                return num;
        }
        return -1;
    }

    int majorityElement2(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }

    int majorityElement3(vector<int>& nums)
    {
        int candidate = -1;
        int count = 0;
        for (int num : nums)
        {
            if (num == candidate)
                ++count;
            else if (--count < 0)
            {
                candidate = num;
                count = 1;
            }
        }
        return candidate;
    }
};

int main()
{
    cout << "---------------" << endl;
    Solution s;
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << s.majorityElement1(nums) << endl;
    cout << s.majorityElement2(nums) << endl;
    cout << s.majorityElement3(nums) << endl;
    cout << "---------------" << endl;
    return 0;
}
