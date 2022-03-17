#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int preSum = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            preSum = max(preSum + nums[i], nums[i]);
            maxSum = max(maxSum, preSum);
        }

        return maxSum;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(nums) << endl;
    cout << "--------------------" << endl;
    return 0;
}
