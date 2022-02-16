#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int farthest = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (farthest < i)
                return false;
            else if (farthest >= nums.size() - 1)
                return true;
            else if (farthest < nums[i] + i)
                farthest = nums[i] + i;
        }
        return false;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1, 1, 1, 0};
    cout << s.canJump(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
