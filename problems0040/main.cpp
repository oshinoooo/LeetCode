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
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int> tmp;
        vector<vector<int>> out;
        myPermute(nums, used, tmp, out);
        return out;
    }

private:
    void myPermute(vector<int>& nums, vector<bool>& used, vector<int>& tmp, vector<vector<int>>& out) {
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i])
                continue;

            used[i] = true;
            tmp.push_back(nums[i]);

            if (tmp.size() == nums.size())
                out.push_back(tmp);
            else
                myPermute(nums, used, tmp, out);

            tmp.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> out = s.permute(nums);
    for (auto ou : out) {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
