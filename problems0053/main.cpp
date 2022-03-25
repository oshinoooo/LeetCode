#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int curSum = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            curSum = max(curSum + nums[i], nums[i]);
            maxSum = max(maxSum, curSum);
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
