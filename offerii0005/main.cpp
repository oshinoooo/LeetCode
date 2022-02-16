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
    int maxProduct(vector<string>& words) {
        vector<int> binary;
        for (auto& word : words) {
            int tmp = 0;
            for (auto& c : word) {
                tmp |= 1 << (c - 'a');
            }
            binary.push_back(tmp);
        }

        int out = 0;
        for (int i = 0; i < binary.size(); ++i) {
            for (int j = i + 1; j < binary.size(); ++j) {
                if ((binary[i] & binary[j]) == 0) {
                    out = max(out, (int)words[i].size() * (int)words[j].size());
                }
            }
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<string> words = {"abcw","baz","foo","bar","fxyz","abcdef"};
    cout << s.maxProduct(words) << endl;
    cout << "---------------------" << endl;
    return 0;
}
