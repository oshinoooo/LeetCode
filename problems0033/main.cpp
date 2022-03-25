#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int head = 0;
        int tail = nums.size() - 1;

        while (head <= tail) {
            int mid = (head + tail) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[0] <= target) {
                if (nums[mid] < target && nums[0] <= nums[mid])
                    head = mid + 1;
                else
                    tail = mid - 1;
            }
            else {
                if (target < nums[mid] && nums[mid] < nums[0])
                    tail = mid - 1;
                else
                    head = mid + 1;
            }
        }

        return -1;
    }
};

int main()
{
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout << s.search(nums, target) << endl;
    cout << "--------------------" << endl;
    return 0;
}