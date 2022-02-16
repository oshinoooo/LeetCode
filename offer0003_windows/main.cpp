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
    int findRepeatNumber1(vector<int>& nums) {
        unordered_set<int> s;
        for (auto& num : nums) {
            if (s.count(num)) {
                return num;
            }
            else {
                s.insert(num);
            }
        }
        return -1;
    }

    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (i == nums[i]) {
                continue;
            }
            if (nums[nums[i]] == nums[i]) {
                return nums[i];
            }
            else {
                swap(nums[nums[i]], nums[i]);
                --i;
            }
        }
        return -1;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {2, 3, 1, 0, 2, 5, 3};
    cout << s.findRepeatNumber(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
