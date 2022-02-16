#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> out;
        vector<int> combine;
        dfs(candidates, target, out, combine, 0);
        return out;
    }

private:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& out, vector<int>& combine, int idx)
    {
        if (idx == candidates.size())
            return;

        if (target == 0)
        {
            out.emplace_back(combine);
            return;
        }

        // 直接跳过
        dfs(candidates, target, out, combine, idx + 1);
        // 选择当前数
        if (target - candidates[idx] >= 0)
        {
            combine.emplace_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], out, combine, idx);
            combine.pop_back();
        }
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> out = s.combinationSum(candidates, target);
    for (auto ou : out)
    {
        for (auto o : ou)
            cout  << o << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
