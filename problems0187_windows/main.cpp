#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences1(string s)
    {
        if (s.size() < 10)
            return {};

        set<string> store;
        for (int i = 0; i < s.size() - 10; ++i)
        {
            string tmp = s.substr(i, 10);
            if (store.count(tmp))
            {
                store.insert(tmp);
                continue;
            }

            for (int j = i + 1; j < s.size() - 9; ++j)
            {
                if (tmp == s.substr(j, 10))
                {
                    store.insert(s.substr(i, 10));
                    break;
                }
            }
        }

        vector<string> out;
        for (auto sto : store)
            out.emplace_back(sto);

        return out;
    }

    vector<string> findRepeatedDnaSequences2(string s)
    {
        if (s.size() < 10)
            return {};

        vector<string> out;
        unordered_map<string, int> count;

        for (int i = 0; i <= s.length() - 10; ++i)
        {
            string sub = s.substr(i, 10);
            if (++count[sub] == 2)
                out.push_back(sub);
        }

        return out;
    }

    vector<string> findRepeatedDnaSequences(string s)
    {
        if (s.length() <= 10)
            return {};

        unordered_map<char, int> bin = {{'A', 0}, {'C', 1},
                                        {'G', 2}, {'T', 3}};

        int x = 0;
        for (int i = 0; i < 9; ++i)
        {
            x <<= 2;
            x |= bin[s[i]];
        }

        vector<string> out;
        unordered_map<int, int> count;
        for (int i = 0; i <= s.length() - 10; ++i)
        {
            x <<= 2;
            x |= bin[s[i + 9]];
            x &= (1 << 20) - 1;

            if (++count[x] == 2)
                out.push_back(s.substr(i, 10));
        }
        return out;
    }
};

int main()
{
    cout << "-------------------------" << endl;
    Solution s;
    vector<string> out = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTTCCAAAAAGGGGTTTCCAAA");
    for (auto ou : out)
        cout << ou << endl;
    cout << "-------------------------" << endl;
    return 0;
}
