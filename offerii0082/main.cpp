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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        vector<vector<int>> out;
        myCombinationSum(candidates, target, tmp, 0, 0, out);
        return out;
    }

private:
    void myCombinationSum(vector<int>& candidates, int& target, vector<int>& tmp, int sum, int cur, vector<vector<int>>& out) {
        for (int i = cur; i < candidates.size(); ++i) {
            if (cur < i && candidates[i - 1] == candidates[i])
                continue;

            if (sum + candidates[i] == target) {
                tmp.push_back(candidates[i]);
                out.push_back(tmp);
                tmp.pop_back();
            }
            else if (sum + candidates[i] < target) {
                tmp.push_back(candidates[i]);
                myCombinationSum(candidates, target, tmp, sum + candidates[i], i + 1, out);
                tmp.pop_back();
            }
            else
                break;
        }
    }
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
