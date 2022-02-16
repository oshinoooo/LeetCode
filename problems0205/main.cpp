#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        map<char, char> match;
        set<char> used;
        for (int i = 0; i < s.size(); ++i)
        {
            if (match.count(s[i]) == 0)
            {
                if (used.count(t[i]) == 0)
                {
                    match.insert({s[i], t[i]});
                    used.insert(t[i]);
                }
                else
                    return false;
            }
            else
            {
                if (match[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    cout << "-----------------" << endl;
    Solution s;
    cout << s.isIsomorphic("badc", "baba") << endl;
    cout << "-----------------" << endl;
    return 0;
}
