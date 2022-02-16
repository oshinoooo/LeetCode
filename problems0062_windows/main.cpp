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

class Solution
{
public:
    int uniquePaths1(int m, int n)
    {
        return my_uniquePaths(m, n, 0, 0);
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
        return dp[m - 1][n - 1];
    }

private:
    int my_uniquePaths(int& m, int& n, int x, int y)
    {
        if (m <= x || n <= y)
            return 0;

        if (m - 1 == x && n - 1 == y)
            return 1;

        return my_uniquePaths(m, n, x + 1, y) + my_uniquePaths(m, n, x, y + 1);
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.uniquePaths(23, 12) << endl;
    cout << "---------------------" << endl;
    return 0;
}
