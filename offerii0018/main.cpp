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
    bool isPalindrome(string s) {
        string s1;
        for (auto& c : s) {
            if (isalnum(c))
                s1.push_back(tolower(c));
        }
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        return s1 == s2;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << "---------------------" << endl;
    return 0;
}
