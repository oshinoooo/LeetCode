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
    string longestPalindrome1(string s) {
        int size = s.size();
        string out;

        for (int i = 0; i < size; ++i) {
            int length = 0;

            while (0 <= i - (length + 1) && i + (length + 1) < size && s[i - (length + 1)] == s[i + (length + 1)])
                ++length;

            if (out.size() < length * 2 + 1)
                out = s.substr(i - length, length * 2 + 1);
        }

        for (int i = 1; i < size; ++i) {
            if (s[i - 1] == s[i]) {
                int length = 0;

                while (0 <= (i - 1) - (length + 1) && i + (length + 1) < size && s[(i - 1) - (length + 1)] == s[i + (length + 1)])
                    ++length;

                if (out.size() < length * 2 + 2)
                    out = s.substr(i - 1 - length, length * 2 + 2);
            }
        }

        return out;
    }

    string longestPalindrome(string s) {
        int size = s.size();
        string out;
        vector<vector<bool>> dp(size, vector<bool>(size, false));

        for (int length = 1; length <= size; ++length) {
            for (int left = 0; left < size; ++left) {
                int right = left + length - 1;

                if (size <= right)
                    break;

                if (s[left] == s[right]) {
                    if (length <= 2)
                        dp[left][right] = true;
                    else
                        dp[left][right] = dp[left + 1][right - 1];
                }

                if (dp[left][right] && out.size() < length)
                    out = s.substr(left, length);
            }
        }

        return out;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    cout << s.longestPalindrome("babad") << endl;
    cout << "---------------------" << endl;
    return 0;
}
