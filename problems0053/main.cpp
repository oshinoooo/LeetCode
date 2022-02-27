#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray1(vector<int>& nums) {
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

    int maxSubArray(vector<int>& nums) {
        int preMin = 0;
        int preSum = 0;
        int maxSum = INT_MIN;

        int head = 0;
        int tail = 0;

        for (int i = 0; i < nums.size(); ++i) {
            preSum += nums[i];

            if (maxSum < preSum - preMin) {
                tail = i;
                maxSum = preSum - preMin;
            }

            if (preSum < preMin) {
                head = min(i + 1, tail);
                preMin = preSum;
            }
        }

        for (int i = head; i <= tail; ++i)
            cout << nums[i] << " ";
        cout << endl;

        return maxSum;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
    cout << s.maxSubArray(nums) << endl;
    cout << "--------------------" << endl;
    return 0;
}
