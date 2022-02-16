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
#include <ctime>

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
        if (nums.size() < 3)
            return nums.back();

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = (high - low) / 2 + low;
            if (mid % 2 == 1)
                --mid;

            if (nums[mid] == nums[mid + 1])
                low = mid + 2;
            else
                high = mid - 2;
        }

        return nums[low];
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
