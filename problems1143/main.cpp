#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestCommonSubsequence1(string text1, string text2)
    {
        int max = 0;
        for (int i = 0; i < text1.size(); ++i)
        {
            for (int j = 0; j < text2.size(); ++j)
            {
                int length = 0;
                while ( i + length < text1.size() &&
                        j + length < text2.size() &&
                        text1[i + length] == text2[j + length])
                    ++length;

                if (max < length)
                    max = length;
            }
        }

        return max;
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m][n];
    }
};

int main()
{
    cout << "---------------" << endl;
    Solution s;
    cout << s.longestCommonSubsequence("12345", "asdf12345") << endl;
    cout << "---------------" << endl;
    return 0;
}
