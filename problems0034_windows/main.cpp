#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int fir = left_boundary(nums, target);

        if (0 <= fir && fir < nums.size())
        {
            for (int i = fir; i < nums.size(); ++i)
            {
                if (nums[fir] != nums[i])
                    return {fir, i - 1};
            }
        }

        return {-1, -1};
    }

private:
    int left_boundary(vector<int>& nums, int target)
    {
        int ptr1 = 0;
        int ptr2 = nums.size();
        int mid = (ptr1 + ptr2) / 2;

        while (ptr1 < ptr2)
        {
            if (nums[mid] == target)
                ptr2 = mid;
            else if (nums[mid] > target)
            {

            }
            else
            {

            }
        }
    }
};

int main()
{
    cout << "---------------" << endl;
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> out = s.searchRange(nums, target);
    cout << "---------------" << endl;
    return 0;
}
