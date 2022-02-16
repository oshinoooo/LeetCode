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
    int maxSubArray1(vector<int>& nums) {
        int maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            int tmpSum = 0;
            for (int j = i; j < nums.size(); ++j) {
                tmpSum += nums[j];
                maxSum = max(maxSum, tmpSum);
            }
        }
        return maxSum;
    }

    int maxSubArray2(vector<int>& nums) {
        vector<int> dp = {nums[0]};
        int maxSum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp.push_back(max(dp.back() + nums[i], nums[i]));
            maxSum = max(maxSum, dp.back());
        }
        return maxSum;
    }

    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;

        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            maxSum = max(maxSum, sum);

            if (sum < 0)
                sum = 0;
        }

        return maxSum;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> num = {-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(num) << endl;
    cout << "---------------------" << endl;
    return 0;
}
