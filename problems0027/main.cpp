#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())
            return 0;

        int tail = nums.size() - 1;
        int cur = 0;
        while (cur <= tail) {
            if (nums[cur] == val) {
                swap(nums[cur], nums[tail]);
                --tail;
            }
            else
                ++cur;
        }
        return cur;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {0,0,0,1,2,3};
    cout << s.removeElement(nums, 0) << endl;
    cout << "--------------------" << endl;
    return 0;
}