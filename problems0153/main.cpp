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
    int findMin1(vector<int>& nums) {
        int ptr1 = 0;
        int ptr2 = nums.size() - 1;

        while (ptr1 < ptr2) {
            int mid = (ptr1 + ptr2) / 2;
            if (nums[mid] < nums[ptr2])
                ptr2 = mid;
            else
                ptr1 = mid + 1;
        }

        return nums[ptr1];
    }

    int findMin(vector<int>& nums) {
        int head = 0;
        int tail = nums.size() - 1;

        while (head < tail) {
            int mid = (head + tail) / 2;
            if (nums[mid] < nums[tail])
                tail = mid;
            else
                head = mid + 1;
        }

        return nums[head];
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {3, 1, 2};
    cout << s.findMin(nums) << endl;
    cout << "--------------------" << endl;
    return 0;
}
