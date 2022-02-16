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
    int pivotIndex1(vector<int>& nums) {
        int right_sum = accumulate(nums.begin(), nums.end(), 0);
        if (right_sum == nums[0])
            return 0;
        int left_sum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0)
                left_sum += nums[i - 1];

            right_sum -= nums[i];

            if (left_sum == right_sum)
                return i;
        }

        return -1;
    }

    int pivotIndex(vector<int> &nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (2 * sum + nums[i] == total) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1,7,3,6,5,6};
    cout << s.pivotIndex(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
