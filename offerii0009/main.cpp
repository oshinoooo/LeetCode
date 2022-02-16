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
    int numSubarrayProductLessThanK1(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = 1;
            for (int j = i; j < nums.size(); ++j) {
                tmp *= nums[j];
                if (tmp < k) {
                    ++count;
                }
                else {
                    break;
                }
            }
        }
        return count;
    }

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int length = nums.size();

        int mul = 1;
        int count = 0;

        int right = 0;
        int left = 0;

        while (right < length) {
            mul *= nums[right];
            while (left <= right && k <= mul) {
                mul /= nums[left++];
            }

            if (left <= right) {
                count += right - left + 1;
            }

            ++right;
        }

        return count;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {10,5,2,6};
    cout << s.numSubarrayProductLessThanK(nums, 100) << endl;
    cout << "---------------------" << endl;
    return 0;
}
