#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
//        int tmp1 = lower_bound(nums.begin(), nums.end(), target).base() - nums.begin().base();
//        int tmp2 = lower_bound(nums.begin(), nums.end(), target + 1).base() - nums.begin().base();
        int tmp1 = lowerBound(nums, target);
        int tmp2 = lowerBound(nums, target + 1);
        if (tmp1 == tmp2)
            return {-1, -1};
        return {tmp1, tmp2 - 1};
    }

private:
    int lowerBound(const vector<int>& nums, const int target) {
        int n = nums.size();

        int ptr1 = 0;
        int ptr2 = n - 1;
        while (ptr1 <= ptr2) {
            int mid = (ptr1 + ptr2) / 2;

            if (nums[mid] == target)
                ptr2 = mid - 1;
            else if (nums[mid] < target)
                ptr1 = mid + 1;
            else
                ptr2 = mid - 1;
        }

        return ptr1;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {0, 1, 1, 2, 2, 3, 3, 5};
    int target = 2;
    vector<int> out = s.searchRange(nums, target);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "--------------------" << endl;
    return 0;
}
