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
#include <ctime>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> count;
        int start = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (i == s1.size() - 1 || s1[i + 1] == ' ') {
                ++count[s1.substr(start, i - start + 1)];
                start = i + 2;
            }
        }

        start = 0;
        for (int i = 0; i < s2.size(); ++i) {
            if (i == s2.size() - 1 || s2[i + 1] == ' ') {
                ++count[s2.substr(start, i - start + 1)];
                start = i + 2;
            }
        }

        vector<string> out;
        for (auto [word, num] : count) {
            if (num == 1)
                out.emplace_back(word);
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<string> out = s.uncommonFromSentences("this apple is sweet", "this apple is sour");
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
