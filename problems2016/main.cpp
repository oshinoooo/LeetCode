#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff = -1;
        int minPrev = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (minPrev < nums[i])
                maxDiff = max(maxDiff, nums[i] - minPrev);
            minPrev = min(minPrev, nums[i]);
        }
        return maxDiff;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {7,1,5,4};
    cout << s.maximumDifference(nums) << endl;
    cout << "--------------------" << endl;
    return 0;
}
