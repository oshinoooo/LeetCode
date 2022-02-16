#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int left = left_boundary(nums, target);

        if (left == -1)
            return {-1, -1};

        int i;
        for (i = left; i < nums.size(); ++i)
        {
            if (nums[left] != nums[i])
                break;
        }
        return {left, i - 1};
    }

private:
    int left_boundary(vector<int>& nums, int target)
    {
        int ptr1 = 0;
        int ptr2 = nums.size();

        while (ptr1 < ptr2)
        {
            int mid = (ptr1 + ptr2) / 2;
            if (nums[mid] == target)
                ptr2 = mid;
            else if (nums[mid] < target)
                ptr1 = mid + 1;
            else if (nums[mid] > target)
                ptr2 = mid;
        }

        if (ptr1 == nums.size() || nums[ptr1] != target)
            return -1;

        return ptr1;
    }
};

int main()
{
    cout << "---------------" << endl;
    Solution s;
    vector<int> nums = {1};
    int target = 1;
    vector<int> out = s.searchRange(nums, target);
    cout << out[0] << " " << out[1] << endl;
    cout << "---------------" << endl;
    return 0;
}
