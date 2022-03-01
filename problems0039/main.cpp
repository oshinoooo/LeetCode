#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        vector<vector<int>> out;
        myCombinationSum(candidates, target, 0, tmp, out);
        return out;
    }

private:
    void myCombinationSum(const vector<int>& candidates, int target, int index, vector<int>& tmp, vector<vector<int>>& out) {
        if (target == 0) {
            out.push_back(tmp);
            return;
        }

        if (target < 0 || candidates.size() <= index)
            return;

        tmp.push_back(candidates[index]);
        myCombinationSum(candidates, target - candidates[index], index, tmp, out);
        tmp.pop_back();

        myCombinationSum(candidates, target, index + 1, tmp, out);
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> out = s.combinationSum(candidates, target);
    for (auto ou : out) {
        for (auto o : ou)
            cout  << o << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
