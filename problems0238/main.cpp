#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> left(n, 1);
        for (int i = 0; i < n - 1; ++i)
            left[i + 1] = left[i] * nums[i];

        vector<int> right(n, 1);
        for (int i = n - 1; 0 < i; --i)
            right[i - 1] = right[i] * nums[i];

        vector<int> out;
        for (int i = 0; i < n; ++i)
            out.push_back(left[i] * right[i]);

        return out;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {-1,1,0,-3,3};
    vector<int> out = s.productExceptSelf(nums);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "--------------------" << endl;
    return 0;
}