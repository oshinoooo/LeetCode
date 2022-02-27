#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray1(vector<int>& nums) {
        if (nums.empty()) return 0;
        int max = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            int sum = nums[i];
            if (sum > max)
                max = sum;
            for (int j = i + 1; j < nums.size(); ++j) {
                sum += nums[j];
                if (sum > max)
                    max = sum;
            }
        }
        return max;
    }

    int maxSubArray2(vector<int>& nums) {
        if (nums.empty()) return 0;
        int out = nums[0];
        vector<int> sum = {nums[0]};

        for (int i = 1; i < nums.size(); ++i) {
            int tmp = max(sum[i - 1] + nums[i], nums[i]);
            sum.push_back(tmp);
            if (out < tmp)
                out = tmp;
        }
        return out;
    }

    int maxSubArray(vector<int>& nums) {

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
