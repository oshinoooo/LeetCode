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
    vector<string> findOcurrences(string text, string first, string second)
    {
        vector<string> words;
        int ptr = 0;
        for (int i = 0; i < text.size(); ++i)
        {
            if (text[i] == ' ')
            {
                words.push_back(text.substr(ptr, i - ptr));
                ptr = i + 1;
            }
            else if (i == text.size() - 1)
                words.push_back(text.substr(ptr, i - ptr + 1));
        }

        vector<string> out;
        for (int i = 0; i < words.size() - 1; ++i)
        {
            if (words[i] == first && words[i + 1] == second && i + 2 < words.size())
                out.push_back(words[i + 2]);
        }

        return out;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<string> out = s.findOcurrences("alice is a good girl she is a good student", "a", "good");
    for (auto str : out)
        cout << str << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
