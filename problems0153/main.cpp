#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int ptr1 = 0;
        int ptr2 = nums.size() - 1;

        while (ptr1 < ptr2) {
            int mid = (ptr1 + ptr2) / 2;

            // 顺序
            if (nums[ptr1] <= nums[mid] && nums[mid] <= nums[ptr2])
                return nums[ptr1];

            // 逆序
            if (nums[ptr1] <= nums[mid] && nums[mid] >= nums[ptr2])
                ptr1 = mid + 1;
            else if (nums[ptr1] >= nums[mid] && nums[mid] <= nums[ptr2])
                ptr2 = mid;
        }

        return nums[ptr1];
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {2, 1};
    cout << s.findMin(nums) << endl;
    cout << "--------------------" << endl;
    return 0;
}
