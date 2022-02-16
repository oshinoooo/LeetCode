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
    int findMaxLength(vector<int>& nums) {
        int max_len = 0;
        int cur_sum = 0;
        unordered_map<int, int> m = {{0, -1}};

        for (int i = 0; i < nums.size(); ++i) {
            cur_sum += nums[i] == 0 ? -1 : 1;
            if (m.count(cur_sum))
                max_len = max(max_len, i - m[cur_sum]);
            else
                m[cur_sum] = i;
        }

        return max_len;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {0, 1, 0, 1, 1, 1, 1, 1, 1};
    cout << s.findMaxLength(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
