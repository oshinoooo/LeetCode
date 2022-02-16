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
    bool isAnagram(string s, string t) {
        if (s == t || s.size() != t.size())
            return false;

        unordered_map<char, int> m_s;
        for (auto& c : s)
            ++m_s[c];

        unordered_map<char, int> m_t;
        for (auto& c : t)
            ++m_t[c];

        return m_s == m_t;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.isAnagram("123", "321") << endl;
    cout << "---------------------" << endl;
    return 0;
}
