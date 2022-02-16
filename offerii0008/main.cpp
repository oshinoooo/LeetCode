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
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_length = INT_MAX;
        int head = 0;
        int tail = 0;
        int sum = 0;

        while (head < nums.size() || tail < nums.size()) {
            while (tail < nums.size() && sum < target) {
                sum += nums[tail++];
            }

            if (target <= sum) {
                min_length = min(min_length, tail - head);
            }

            sum -= nums[head++];
        }

        return min_length == INT_MAX ? 0 : min_length;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1,1,1,1,1,1,1,1};
    cout << s.minSubArrayLen(11, nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
