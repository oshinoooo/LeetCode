#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());

        string out;
        int maxLength = 0;
        for (string str : s) {
            for (int i = 0; i < str.size(); ++i) {
                if (!s.count(str.substr(0, i + 1))) {
                    break;
                }

                if (i == str.size() - 1) {
                    if (maxLength < str.size()) {
                        maxLength = str.size();
                        out = str;
                    }
                    else if (maxLength == str.size()) {
                        out = out < str ? out : str;
                    }
                }
            }
        }

        return out;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<string> words = {"w","wo","wor","worl", "world"};
    cout << s.longestWord(words) << endl;
    cout << "--------------------" << endl;
    return 0;
}
