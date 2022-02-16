#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cctype>
#include <numeric>
#include <math.h>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;

        for (int i = 0; i < nums.size(); ++i) {
            if (s.count(nums[i]))
                return true;
            else
                s.insert(nums[i]);

            if (k + 1 <= s.size())
                s.erase(nums[i - k]);
        }

        return false;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1,2,3,1};
    int k = 3;
    cout << s.containsNearbyDuplicate(nums, k) << endl;
    cout << "---------------------" << endl;
    return 0;
}
