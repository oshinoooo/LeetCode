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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> tmp;
        mySubsets(nums, 0, tmp, out);
        return out;
    }

private:
    void mySubsets(const vector<int>& nums, int ptr, vector<int>& tmp, vector<vector<int>>& out) {
        if (nums.size() - 1 < ptr) {
            out.push_back(tmp);
            return;
        }

        mySubsets(nums, ptr + 1, tmp, out);

        tmp.push_back(nums[ptr]);
        mySubsets(nums, ptr + 1, tmp, out);
        tmp.pop_back();
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> out = s.subsets(nums);
    for (auto ou : out) {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
