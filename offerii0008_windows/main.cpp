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
    int minSubArrayLen1(int target, vector<int>& nums) {
        int minLength = INT_MAX;
        bool found = false;

        for (int i = 0; i < nums.size(); ++i) {
            int tmpSum = 0;
            for (int j = i; j < nums.size(); ++j) {
                tmpSum += nums[j];
                if (target <= tmpSum) {
                    minLength = min(minLength, j - i + 1);
                    found = true;
                }
            }
        }

        if (found)
            return minLength;
        return 0;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength = INT_MAX;
        bool found = false;

        int start = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while (target <= sum) {
                found = true;
                minLength = min(minLength, i - start + 1);
                sum -= nums[start++];
            }
        }

        if (found)
            return minLength;
        return 0;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};
    cout << s.minSubArrayLen(target, nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
