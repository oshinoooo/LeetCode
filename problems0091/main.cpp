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
        if (s[0] == '0')
            return 0;

        vector<int> dp = {1, 1};
        for (int i = 1; i < s.size(); ++i) {
            int tmp = 0;

            if (s[i] == '0') {
                if (s[i - 1] != '0' && (s[i - 1] - '0') * 10 + (s[i] - '0') <= 26)
                    tmp += dp[dp.size() - 2];
                else
                    return 0;
            }
            else if (s[i] != '0') {
                tmp += dp[dp.size() - 1];

                if (s[i - 1] != '0' && (s[i - 1] - '0') * 10 + (s[i] - '0') <= 26)
                    tmp += dp[dp.size() - 2];
            }

            dp.push_back(tmp);
        }

        return dp.back();
    }
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    cout << s.numDecodings("230") << endl;
    cout << "--------------------" << endl;
    return 0;
}
