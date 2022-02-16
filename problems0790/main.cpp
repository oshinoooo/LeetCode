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
    int numTilings(int n)
    {
        int MOD = 1000000007;
        vector<long> dp = {1, 0, 0, 0};
        for (int i = 0; i < n; ++i)
        {
            vector<long> ndp(4);
            ndp[0] = (dp[0] + dp[3]) % MOD;
            ndp[1] = (dp[0] + dp[2]) % MOD;
            ndp[2] = (dp[0] + dp[1]) % MOD;
            ndp[3] = (dp[0] + dp[1] + dp[2]) % MOD;
            dp = ndp;
        }
        return dp[0];
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.numTilings(3) << endl;
    cout << "---------------------" << endl;
    return 0;
}
