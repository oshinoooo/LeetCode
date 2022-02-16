#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> out;
        int pre = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[pre] == nums[i] && pre == i - 1)
                out.push_back(nums[pre]);
            else if (nums[pre] != nums[i])
                pre = i;
        }
        return out;
    }
};

int main()
{
    cout << "-------------------------" << endl;
    Solution s;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> out = s.findDuplicates(nums);
    for (auto ou : out)
        cout << ou << " ";
    cout << endl;
    cout << "-------------------------" << endl;
    return 0;
}
