#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> used(n, false);
        vector<int> tmp;
        vector<vector<int>> out;
        myPermute(nums, used, tmp, out);
        return out;
    }

private:
    void myPermute(const vector<int>& nums, vector<bool>& used, vector<int>& tmp, vector<vector<int>>& out) {
        int n = nums.size();

        if (tmp.size() == n) {
            out.push_back(tmp);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (used[i])
                continue;
            used[i] = true;
            tmp.push_back(nums[i]);
            myPermute(nums, used, tmp, out);
            tmp.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> outs = s.permute(nums);
    for (auto out : outs) {
        for (auto num : out)
            cout << num << " ";
        cout << endl;
    }
    cout << "--------------------" << endl;
    return 0;
}
