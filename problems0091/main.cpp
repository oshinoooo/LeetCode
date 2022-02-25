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
    int numDecodings(string s) {
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
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    cout << s.numDecodings("11106") << endl;
    cout << "--------------------" << endl;
    return 0;
}
