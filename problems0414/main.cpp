#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{
public:
    int thirdMax1(vector<int>& nums)
    {
        sort(nums.begin(), nums.end(), greater<>());
        for (int i = 1, count = 1; i < nums.size(); ++i)
        {
            if (nums[i - 1] != nums[i] && ++count == 3)
                return nums[i];
        }
        return nums[0];
    }

    int thirdMax(vector<int>& nums)
    {
        set<int> s;
        for (auto num : nums)
        {
            s.insert(num);
            if (s.size() > 3)
                s.erase(s.begin());
        }
        return s.size() == 3 ? *s.begin() : *s.rbegin();
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1, 1, 2};
    cout << s.thirdMax(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
