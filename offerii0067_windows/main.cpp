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
    int findMaximumXOR1(vector<int>& nums) {
        int out = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j)
                out = max(out, nums[i] ^ nums[j]);
        }
        return out;
    }

    int findMaximumXOR(vector<int>& nums) {

    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {3,10,5,25,2,8};
    cout << s.findMaximumXOR(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
