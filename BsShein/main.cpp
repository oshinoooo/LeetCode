#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecoding(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] != '0')
                dp[i] += dp[i - 1];

            if (2 <= i && s[i - 2] != '0') {
                if ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)
                    dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }

    int strStr(string haystack, string needle) {
        for (int i = 0; i <= haystack.size() - needle.size(); ++i) {
            if (haystack.substr(i, needle.size()) == needle)
                return i;
        }
        return -1;
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    cout << s.numDecoding("11106") << endl;
    cout << s.strStr("shein", "in") << endl;
    cout << "--------------------" << endl;
    return 0;
}
