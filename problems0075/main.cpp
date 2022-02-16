#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        int ptr0 = 0;
        int ptr2 = nums.size() - 1;

        for (int i = 0; i <= ptr2; ++i)
        {
            if (nums[i] == 0)
            {
                swap(nums[i], nums[ptr0]);
                ++ptr0;
            }
            else if (nums[i] == 2)
            {
                swap(nums[i], nums[ptr2]);
                --i;
                --ptr2;
            }
        }
    }
};

int main()
{
    cout << "-------------------------" << endl;
    Solution s;
    vector<int> nums = {2,0,1};
    s.sortColors(nums);
    for (auto num : nums)
        cout << num << " ";
    cout << endl;
    cout << "-------------------------" << endl;
    return 0;
}
