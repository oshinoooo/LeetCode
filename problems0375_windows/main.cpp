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
    int getMoneyAmount1(int n)
    {
        int sum = test(1, n);
        return sum;
    }

    int getMoneyAmount(int n)
    {
        vector<vector<int>> f(n+1,vector<int>(n+1));
        for (int i = n - 1; i >= 1; i--)
        {
            for (int j = i + 1; j <= n; j++)
            {
                int minCost = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    int cost = k + max(f[i][k - 1], f[k + 1][j]);
                    minCost = min(minCost, cost);
                }
                f[i][j] = minCost;
            }
        }
        return f[1][n];
    }
private:
    int test(int left, int right)
    {
        if (left >= right)
            return 0 ;
        int sum = INT_MAX;
        for (int i = left; i <= right; ++i)
            sum = min(sum, i + max(test(left, i - 1), test(i + 1, right)));
        return sum;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.getMoneyAmount(20) << endl;
    cout << "---------------------" << endl;
    return 0;
}
