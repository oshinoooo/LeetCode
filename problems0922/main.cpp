#include <iostream>
#include <vector>
#include<bitset>

using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int>& nums)
    {
        int ptr_even = 0;
        int ptr_odd = 1;
        while (ptr_even < nums.size() - 1 && ptr_odd < nums.size())
        {
            if (nums[ptr_even] % 2 == 0)
            {
                ptr_even += 2;
                continue;
            }

            if (nums[ptr_odd] % 2 == 1)
            {
                ptr_odd += 2;
                continue;
            }

            swap(nums[ptr_even], nums[ptr_odd]);
        }
        return nums;
    }
};

int main()
{
    std::cout << "---------------" << std::endl;
    Solution s;
    vector<int> nums = {4,2,5,7};
    vector<int> out = s.sortArrayByParityII(nums);
    for (auto o : out)
        cout << o << " ";
    cout << endl;
    std::cout << "---------------" << std::endl;
    return 0;
}
