#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[0].size(); ++j) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        return dp.back().back();
    }
};

int main()
{
    cout << "----------------------------------------" << endl;
    Solution s;
    cout << s.longestCommonSubsequence("12345", "asdf12345") << endl;
    cout << "----------------------------------------" << endl;
    return 0;
}
