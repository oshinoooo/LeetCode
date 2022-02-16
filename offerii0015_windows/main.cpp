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
    vector<int> findAnagrams(string s, string p) {
        vector<int> v2(26, 0);
        for (auto& c : p)
            ++v2[c - 'a'];

        vector<int> out;
        vector<int> v1(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            ++v1[s[i] - 'a'];

            if (p.size() <= i)
                --v1[s[i - p.size()] - 'a'];

            if (v1 == v2)
                out.push_back(i - p.size() + 1);
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> out = s.findAnagrams("cbaebabacd", "abc");
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
