#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool containsDuplicate1(vector<int>& nums)
    {
        set<int> count;
        for (auto num : nums)
        {
            if (count.count(num))
                return true;
            else
                count.insert(num);
        }
        return false;
    }

    bool containsDuplicate(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i)
        {
             if (nums[i - 1] == nums[i])
                 return true;
        }
        return false;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    cout << s.containsDuplicate(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
