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
    int maxProduct1(vector<string>& words)
    {
        int max_mul = 0;

        for (int i = 0; i < words.size(); ++i)
        {
            for (int j = 1; j < words.size(); ++j)
            {
                set<char> s;
                for (auto c : words[i])
                    s.insert(c);

                bool duplicate = false;
                for (auto c : words[j])
                {
                    if (s.count(c))
                    {
                        duplicate = true;
                        break;
                    }
                }

                if (!duplicate)
                    max_mul = max(max_mul, (int)(words[i].size() * words[j].size()));
            }
        }

        return max_mul;
    }

    int maxProduct2(vector<string>& words)
    {
        vector<int> mask;
        for (auto& word : words)
        {
            int tmp = 0;
            for (auto& c : word)
                tmp |= 1 << (c - 'a');
            mask.push_back(tmp);
        }

        int max_mul = 0;
        for (int i = 0; i < words.size(); ++i)
        {
            for (int j = i + 1; j < words.size(); ++j)
            {
                if ((mask[i] & mask[j]) == 0)
                    max_mul = max(max_mul, (int)(words[i].size() * words[j].size()));
            }
        }

        return max_mul;
    }

    int maxProduct(vector<string>& words)
    {
        map<int, int> mask;
        for (auto& word : words)
        {
            int tmp = 0;
            for (auto& c : word)
                tmp |= 1 << (c - 'a');

            mask[tmp] = max(mask[tmp], (int)word.size());
        }

        vector<pair<int, int>> mask2;
        for (auto m : mask)
            mask2.push_back({m.first, m.second});

        int max_mul = 0;
        for (int i = 0; i < mask2.size(); ++i)
        {
            for (int j = i + 1; j < mask2.size(); ++j)
            {
                if ((mask2[i].first & mask2[j].first) == 0)
                    max_mul = max(max_mul, (int)(mask2[i].second * mask2[j].second));
            }
        }

        return max_mul;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};
    cout << s.maxProduct(words) << endl;
    cout << "---------------------" << endl;
    return 0;
}
