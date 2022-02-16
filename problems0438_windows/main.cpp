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
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> v_p(26, 0);
        for (auto& c : p)
            ++v_p[c - 'a'];

        vector<int> out;
        vector<int> v_s(26, 0);
        for (int i = 0; i < s.size(); ++i)
        {
            ++v_s[s[i] - 'a'];
            if (p.size() - 1 <= i)
            {
                if (v_s == v_p)
                    out.push_back(i - p.size() + 1);
                --v_s[s[i - p.size() + 1] - 'a'];
            }
        }

        return out;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> out = s.findAnagrams("cbaebabacd", "abc");
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
