#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for (int& num : candidates)
            ++m[num];
        myCombinationSum2(candidates, target, 0);
        return out;
    }

private:
    void myCombinationSum2(const vector<int>& candidates, int target, int index) {
        if (target == 0) {
            out.push_back(tmp);
            return;
        }
        else if (target < 0 || candidates.size() <= index)
            return;

        for (int i = 0; i <= m[candidates[index]]; ++i) {
            for (int j = 0; j < i; ++j)
                tmp.push_back(candidates[index]);

            myCombinationSum2(candidates, target - candidates[index] * i, index + m[candidates[index]]);

            for (int j = 0; j < i; ++j)
                tmp.pop_back();
        }
    }

private:
    map<int, int> m;
    vector<int> tmp;
    vector<vector<int>> out;
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> out = s.combinationSum2(candidates, target);
    for (auto ou : out) {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
