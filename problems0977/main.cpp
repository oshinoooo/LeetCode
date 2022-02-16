#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        int min_index;
        int min_num = INT_MAX;
        for (int i = 0; i < nums.size(); ++i)
        {
            nums[i] *= nums[i];
            if (nums[i] < min_num)
            {
                min_num = nums[i];
                min_index = i;
            }
        }

        int ptr1 = min_index;
        int ptr2 = min_index + 1;
        vector<int> out;

        while (0 <= ptr1 || ptr2 < nums.size())
        {
            if (ptr1 == -1)
            {
                out.push_back(nums[ptr2]);
                ++ptr2;
            }
            else if (nums.size() == ptr2)
            {
                out.push_back(nums[ptr1]);
                --ptr1;
            }
            else if (nums[ptr1] < nums[ptr2])
            {
                out.push_back(nums[ptr1]);
                --ptr1;
            }
            else
            {
                out.push_back(nums[ptr2]);
                ++ptr2;
            }
        }
        return out;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {-5,-3,-2,-1};
    vector<int> out = s.sortedSquares(nums);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
