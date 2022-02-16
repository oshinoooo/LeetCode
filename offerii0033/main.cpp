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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto& str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            if (m.count(tmp))
                m[tmp].push_back(str);
            else
                m.insert({tmp, {str}});
        }

        vector<vector<string>> out;
        for (auto& str : m)
            out.push_back(str.second);

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> out = s.groupAnagrams(strs);
    for (auto ou : out) {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
