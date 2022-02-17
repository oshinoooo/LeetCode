#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int>& nums) {
        int length = nums.size();

        bool found = false;
        int indexRight = -1;
        for (int i = length - 1; 1 <= i; --i) {
            if (nums[i - 1] < nums[i]) {
                found = true;
                indexRight = i - 1;
                break;
            }
        }

        if (found) {
            int indexSmall;
            for (int i = length - 1; 1 <= i; --i) {
                if (nums[indexRight] < nums[i]) {
                    indexSmall = i;
                    break;
                }
            }

            swap(nums[indexRight], nums[indexSmall]);
        }

        sort(nums.begin() + indexRight + 1, nums.end());

        return;
    }
};

int main()
{
    cout << "---------------" << endl;
    Solution s;
    vector<int> nums = {4, 3, 2};
    s.nextPermutation(nums);
    for (auto num : nums)
        cout << num << " ";
    cout << endl;
    cout << "---------------" << endl;
    return 0;
}
