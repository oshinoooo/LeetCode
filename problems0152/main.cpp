#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct1(vector<int>& nums) {
        int n = nums.size();

        int maxMul = INT_MIN;

        for (int i = 0; i < n; ++i) {
            int tmpMul = 1;
            for (int j = i; j < n; ++j) {
                tmpMul *= nums[j];
                maxMul = max(maxMul, tmpMul);
            }
        }

        return maxMul;
    }

    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxProd = nums[0];
        vector<int> dpMax(nums);
        vector<int> dpMin(nums);

        for (int i = 1; i < n; ++i) {
            dpMax[i] = max(nums[i], max(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i]));
            dpMin[i] = min(nums[i], min(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i]));
            maxProd = max(maxProd, dpMax[i]);
        }

        return maxProd;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {2,-1,1,1};
    cout << s.maxProduct(nums) << endl;
    cout << "--------------------" << endl;
    return 0;
}
