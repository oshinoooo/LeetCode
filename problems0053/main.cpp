#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int preMin = 0;
        int preSum = 0;
        int maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            preSum += nums[i];
            maxSum = max(maxSum, preSum - preMin);
            preMin = min(preMin, preSum);
        }
        return maxSum;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {-1};
    cout << s.maxSubArray(nums) << endl;
    cout << "--------------------" << endl;
    return 0;
}
