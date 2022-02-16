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

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> m;
        for (int i = 0; i < order.size(); ++i)
            m[order[i]] = i;

        for (int i = 1; i < words.size(); ++i) {
            int min_length = min(words[i].size(), words[i - 1].size());
            if (words[i].size() < words[i - 1].size() && words[i].substr(0, min_length) == words[i - 1].substr(0, min_length))
                return false;

            for (int j = 0; j < min_length; ++j) {
                if (words[i - 1][j] != words[i][j]) {
                    if (m[words[i - 1][j]] < m[words[i][j]])
                        break;
                    else
                        return false;
                }
            }
        }

        return true;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<string> words = {"hello","leetcode"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    cout << s.isAlienSorted(words, order) << endl;
    cout << "---------------------" << endl;
    return 0;
}
