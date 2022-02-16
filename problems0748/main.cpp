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
    string shortestCompletingWord(string licensePlate, vector<string>& words)
    {
        unordered_map<char, int> m;
        for (auto& c : licensePlate)
        {
            if (isalpha(c))
                ++m[tolower(c)];
        }

        string out;
        for (auto& word : words)
        {
            unordered_map<char, int> tmp;
            for (auto& c : word)
                ++tmp[c];

            auto it = m.begin();
            while (it != m.end())
            {
                if (tmp[it->first] < it->second)
                    break;
                ++it;
            }

            if (it == m.end())
            {
                if (out.empty())
                    out = word;
                else if (word.size() < out.size())
                    out = word;
            }
        }

        return out;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    string licensePlate = "1s3 PSt";
    vector<string> words = {"step", "steps", "stripe", "stepple"};
    cout << s.shortestCompletingWord(licensePlate, words) << endl;
    cout << "---------------------" << endl;
    return 0;
}
