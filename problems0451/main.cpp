#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <numeric>
#include <map>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string frequencySort1(string s)
    {
        unordered_map<char, int> count;
        for (auto& c : s)
            ++count[c];

        multimap<int, char> sort;
        for (auto& c : count)
            sort.insert({c.second, c.first});

        string out;
        for (auto it = sort.rbegin(); it != sort.rend(); ++it)
        {
            for (int i = 0; i < it->first; ++i)
                out.push_back(it->second);
        }
        return out;
    }

    string frequencySort(string s)
    {
        unordered_map<char, int> mp;
        int maxFreq = 0;
        for (auto &ch : s)
            maxFreq = max(maxFreq, ++mp[ch]);

        vector<string> buckets(maxFreq + 1);
        for (auto &[ch, num] : mp)
            buckets[num].push_back(ch);

        string ret;
        for (int i = maxFreq; i > 0; i--)
        {
            string &bucket = buckets[i];
            for (auto &ch : bucket)
            {
                for (int k = 0; k < i; k++)
                    ret.push_back(ch);
            }
        }
        return ret;
    }
};

int main()
{
    cout << "------------------" << endl;
    Solution s;
    cout << s.frequencySort("tree") << endl;
    cout << "------------------" << endl;
    return 0;
}