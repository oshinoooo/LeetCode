#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int search1(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target)
                return i;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;

        if (nums.size() == 1)
            return nums[0] == target ? 0 : -1;

        int ptr1 = 0;
        int ptr2 = nums.size() - 1;

        while (ptr1 <= ptr2) {
            int mid = (ptr1 + ptr2) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid])
                    ptr2 = mid - 1;
                else
                    ptr1 = mid + 1;
            }
            else {
                if (nums[mid] < target && target <= nums[nums.size() - 1])
                    ptr1 = mid + 1;
                else
                    ptr2 = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    cout << "---------------" << endl;
    Solution s;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << s.search(nums, target) << endl;
    cout << "---------------" << endl;
    return 0;
}
