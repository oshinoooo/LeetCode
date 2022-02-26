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
    string optimalDivision(vector<int>& nums) {
        int length = nums.size();
        if (length == 1)
            return to_string(nums[0]);
        else if (length == 2)
            return to_string(nums[0]) + "/" + to_string(nums[1]);

        string out;
        for (int i = 0; i < length; ++i) {
            out += to_string(nums[i]);
            if (i != length - 1)
                out += "/";
            if (i == 0)
                out += "(";
            if (i == length - 1)
                out += ")";
        }
        return out;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {2};
    cout << s.optimalDivision(nums) << endl;
    cout << "--------------------" << endl;
    return 0;
}
