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
    long long subArrayRanges1(vector<int>& nums) {
        int n = nums.size();
        long long out = 0;

        for (int i = 0; i < n; ++i) {
            int minNum = INT_MAX;
            int maxNum = INT_MIN;
            for (int j = i; j < n; ++j) {
                minNum = min(minNum, nums[j]);
                maxNum = max(maxNum, nums[j]);
                out += maxNum - minNum;
            }
        }

        return out;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long out = 0;





        return out;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {4,-2,-3,4,1};
    cout << s.subArrayRanges(nums) << endl;
    cout << "--------------------" << endl;
    return 0;
}
