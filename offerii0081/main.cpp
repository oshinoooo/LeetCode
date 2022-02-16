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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> tmp;
        vector<vector<int>> out;
        myCombinationSum(candidates, target, tmp, 0, 0, out);
        return out;
    }

private:
    void myCombinationSum(vector<int>& candidates, int &target, vector<int>& tmp, int sum, int pos, vector<vector<int>>& out) {
        for(int i = pos; i < candidates.size(); ++i) {
            if(sum + candidates[i] == target) {
                tmp.push_back(candidates[i]);
                out.push_back(tmp);
                tmp.pop_back();
            }
            else if(sum + candidates[i] < target) {
                tmp.push_back(candidates[i]);
                myCombinationSum(candidates, target, tmp, sum + candidates[i], i, out);
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
    vector<int> candidates = {2,7,6,3,5,1};
    int target = 9;
    vector<vector<int>> out = s.combinationSum(candidates, target);
    for (auto ou : out) {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
