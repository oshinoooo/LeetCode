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
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        for (auto& c : s)
            ++m[c];

        int count = 0;
        for (auto& [c, num] : m)
            count += num % 2;

        return count <= 1;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.canPermutePalindrome("tactcoa") << endl;
    cout << "---------------------" << endl;
    return 0;
}
