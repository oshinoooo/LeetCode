#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cctype>
#include <numeric>
#include <math.h>

using namespace std;

class Solution {
public:
    int singleNonDuplicate1(vector<int>& nums) {
        int out = 0;
        for (auto& num : nums)
            out ^= num;
        return out;
    }

    int singleNonDuplicate(vector<int>& nums) {
        int ptr1 = 0;
        int ptr2 = nums.size() - 1;

        while (ptr1 < ptr2) {
            int mid = ptr1 + (ptr2 - ptr1) / 2;

            if (nums[mid] == nums[mid + 1])
                ptr1 = mid + 2;
            else if (nums[mid - 1] == nums[mid])
                ptr2 = mid - 2;
            else
                return mid;
        }

        return -1;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    cout << s.singleNonDuplicate(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
