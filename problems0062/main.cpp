#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int uniquePaths1(int m, int n)
    {
        return arrive(m, n, 0, 0);
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> f(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
            f[i][0] = 1;
        for (int i = 0; i < n; ++i)
            f[0][i] = 1;

        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
                f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
        return f[m - 1][n - 1];
    }

private:
    int arrive(int m, int n, int row, int cal)
    {
        if (row >= m || cal >= n)
            return 0;

        if (row == m - 1 && cal == n - 1)
            return 1;

        return arrive(m, n, row, cal + 1) + arrive(m, n, row + 1, cal);
    }
};

int main()
{
    cout << "-----------------" << endl;
    Solution s;
    cout << s.uniquePaths(3, 3) << endl;
    cout << "-----------------" << endl;
    return 0;
}
