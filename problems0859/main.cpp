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
    bool buddyStrings(string s, string goal)
    {
        if (s.size() != goal.size())
            return false;

        if (s == goal)
        {
            map<char, int> m;
            for (int i = 0; i < s.size(); ++i)
            {
                if (2 <= ++m[s[i]])
                    return true;
            }
        }
        else
        {
            vector<int> ptrs;
            for (int i = 0; i < s.size(); ++i)
            {
                if (s[i] != goal[i])
                    ptrs.push_back(i);
            }

            if (ptrs.size() == 2 && s[ptrs[0]] == goal[ptrs[1]] && s[ptrs[1]] == goal[ptrs[0]])
                return true;
        }

        return false;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.buddyStrings("aa", "aa") << endl;
    cout << "---------------------" << endl;
    return 0;
}
