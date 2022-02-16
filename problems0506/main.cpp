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

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int>& score)
    {
        map<int, int> m;
        for (int i = 0; i < score.size(); ++i)
            m[score[i]] = i;

        int i = 1;
        vector<string> out(score.size());
        for (auto it = m.rbegin(); it != m.rend(); ++it)
        {
            if (i == 1)
                out[it->second] = "Gold Medal";
            else if (i == 2)
                out[it->second] = "Silver Medal";
            else if (i == 3)
                out[it->second] = "Bronze Medal";
            else
                out[it->second] = to_string(i);
            ++i;
        }

        return out;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> score = {5,4,3,2,1};
    vector<string> out = s.findRelativeRanks(score);
    for (auto num : out)
        cout << num << endl;
    cout << "---------------------" << endl;
    return 0;
}
