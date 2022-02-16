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
#include <ctime>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;
        for (int i = k - 1; i < nums.size(); ++i)
            minDiff = min(minDiff, nums[i] - nums[i - k + 1]);
        return minDiff;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {90};
    int k = 1;
    cout << s.minimumDifference(nums, k) << endl;
    cout << "---------------------" << endl;
    return 0;
}
