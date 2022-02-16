#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            auto it = s.lower_bound(max(nums[i], INT_MIN + t) - t);
            if (it != s.end() && *it <= min(nums[i], INT_MAX - t) + t)
                return true;

            s.insert(nums[i]);

            if (k <= i)
                s.erase(nums[i - k]);
        }
        return false;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    cout << s.containsNearbyAlmostDuplicate(nums, 3, 0) << endl;
    cout << "---------------------" << endl;
    return 0;
}
