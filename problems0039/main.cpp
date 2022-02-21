#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> out;






        return out;
    }

private:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& out, vector<int>& combine, int idx) {






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
