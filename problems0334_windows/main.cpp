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
    bool increasingTriplet1(vector<int>& nums) {
        int length = nums.size();
        for (int i = 0; i < length - 2; ++i) {
            for (int j = i + 1; j < length - 1; ++j) {
                if (nums[j] <= nums[i])
                    continue;
                for (int k = j + 1; k < length; ++k) {
                    if (nums[k] <= nums[j])
                        continue;
                    else
                        return true;
                }
            }
        }
        return false;
    }

    bool increasingTriplet2(vector<int>& nums) {
        int length = nums.size();
        if (length < 3)
            return false;

        vector<int> minNums = {INT_MAX};
        int tmp = INT_MAX;
        for (int i = 1; i < length; ++i) {
            tmp = min(tmp, nums[i - 1]);
            minNums.push_back(tmp);
        }

        vector<int> maxNums = {INT_MIN};
        tmp = INT_MIN;
        for (int i = length - 2; 0 <= i; --i) {
            tmp = max(tmp, nums[i + 1]);
            maxNums.push_back(tmp);
        }
        reverse(maxNums.begin(), maxNums.end());

        for (int i = 0; i < length; ++i) {
            if (minNums[i] < nums[i] && nums[i] < maxNums[i])
                return true;
        }

        return false;
    }

    bool increasingTriplet(vector<int>& nums) {
        int length = nums.size();
        if (length < 3)
            return false;

        int num1 = nums[0];
        int num2 = INT_MAX;

        for (int i = 1; i < length; i++) {
            if (num2 < nums[i])
                return true;
            else if (num1 < nums[i])
                num2 = nums[i];
            else
                num1 = nums[i];
        }

        return false;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1};
    cout << s.increasingTriplet(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
