#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.empty())
            return "";

        string substr;

        for (int i = 0; i < strs[0].size(); ++i)
        {
            substr.push_back(strs[0][i]);
            for (int j = 1; j < strs.size(); ++j)
            {
                if (strs[j][i] != substr.back() || strs[j].size() <= i)
                {
                    substr.pop_back();
                    return substr;
                }
            }
        }
        return substr;
    }
};

int main()
{
    cout << "-----------------------" << endl;
    Solution s;
    vector<string> in = {"flower", "flow", "flight"};
    cout << s.longestCommonPrefix(in) << endl;
    cout << "-----------------------" << endl;
    return 0;
}
