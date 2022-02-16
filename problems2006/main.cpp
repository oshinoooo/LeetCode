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
    int countKDifference1(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (abs(nums[i] - nums[j]) == k)
                    ++count;
            }
        }
        return count;
    }

    int countKDifference(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            count += m[nums[i] + k] + m[nums[i] - k];
            m[nums[i]]++;
        }
        return count;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1,2,2,1};
    int k = 1;
    cout << s.countKDifference(nums, k) << endl;
    cout << "---------------------" << endl;
    return 0;
}
