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
    int findPeakElement(vector<int>& nums) {
        int length = nums.size();

        if (length == 1)
            return 0;

        int head = 0;
        int tail = length - 1;

        while (head <= tail) {
            int mid = (head + tail) / 2;

            if (mid + 1 < nums.size() && nums[mid] < nums[mid + 1])
                head = mid + 1;
            else
                tail = mid - 1;
        }

        return head;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {0, 1};
    int i = s.findPeakElement(nums);
    cout << i << endl;
    cout << "--------------------" << endl;
    return 0;
}