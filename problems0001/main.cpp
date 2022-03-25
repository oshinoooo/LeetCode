#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); ++i) {
            if (m.count(target - nums[i])) {
                return {m[target - nums[i]], i};
            }
            m[nums[i]] = i;
        }

        return {-1, -1};
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> out = s.twoSum(nums, target);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "--------------------" << endl;
    return 0;
}