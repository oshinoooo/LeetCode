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
    bool checkInclusion(string s1, string s2) {
        vector<int> v1(26, 0);
        for (auto& c : s1)
            ++v1[c - 'a'];

        vector<int> v2(26, 0);
        for (int i = 0; i < s2.size(); ++i) {
            ++v2[s2[i] - 'a'];

            if (s1.size() <= i)
                --v2[s2[i - s1.size()] - 'a'];

            if (v1 == v2)
                return true;
        }

        return false;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.checkInclusion("123", "000123") << endl;
    cout << "---------------------" << endl;
    return 0;
}
