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
    int cuttingRope(int n)
    {
        int max_mul = 0;

        for (int m = 2; m <= n; ++m)
        {
            int tmp_mul = pow(n / m, m - (n % m)) * pow(n / m + 1, n % m);
            max_mul = max(max_mul, tmp_mul);
        }

        return max_mul;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.cuttingRope(8) << endl;
    cout << "---------------------" << endl;
    return 0;
}
