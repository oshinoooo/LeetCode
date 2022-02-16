#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.empty()) return 0;

        int cur = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[cur] != nums[i])
            {
                nums[cur + 1] = nums[i];
                ++cur;
            }
        }
        return cur + 1;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout << s.removeDuplicates(nums) << endl;
    cout << "--------------------" << endl;
    return 0;
}
