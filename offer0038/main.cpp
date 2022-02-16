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
    vector<string> permutation(string s)
    {
        sort(s.begin(), s.end());
        string tmp;
        vector<string> out;
        my_permutation(s, tmp, out);
        return out;
    }

private:
    void my_permutation(string& s, string& tmp, vector<string>& out)
    {
        if (s.empty())
        {
            out.push_back(tmp);
            return;
        }

        for (int i = 0; i < s.size(); ++i)
        {
            if (i != 0 && s[i - 1] == s[i])
                continue;

            tmp.push_back(s[i]);
            string next_s = s.substr(0, i) + s.substr(i + 1, s.size() - i - 1);
            my_permutation(next_s, tmp, out);
            tmp.pop_back();
        }
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<string> out = s.permutation("aab");
    for (auto num : out)
        cout << num << endl;
    cout << "---------------------" << endl;
    return 0;
}
