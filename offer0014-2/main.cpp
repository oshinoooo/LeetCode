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
    int cuttingRope1(int n)
    {
        int max_mul = 0;

        for (int m = 2; m <= n; ++m)
        {

            int tmp1 = fast_power(n / m, m - n % m);
            int tmp2 = fast_power(n / m + 1, n % m);
            int tmp = (tmp1 * tmp2) % 1000000007;
            max_mul = max(max_mul, tmp);
        }

        return max_mul;
    }

    int cuttingRope(int n)
    {
        if(n <= 3)
            return n - 1;

        int b = n % 3;
        int p = 1000000007;
        long rem = 1;
        long x = 3;

        for(int a = n / 3 - 1; a > 0; a /= 2)
        {
            if(a % 2 == 1) rem = (rem * x) % p;
            x = (x * x) % p;
        }

        if(b == 0)
            return (int)(rem * 3 % p);

        if(b == 1)
            return (int)(rem * 4 % p);

        return (int)(rem * 6 % p);
    }

private:
    int fast_power(int base, int power)
    {
        if (power == 0)
            return 1;

        if (power % 2 == 1)
        {
            long long tmp = fast_power(base, power - 1) % 1000000007;
            return (tmp * base) % 1000000007;
        }
        else
        {
            long long tmp = fast_power(base, power / 2) % 1000000007;
            return (tmp * tmp) % 1000000007;
        }

        return -1;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.cuttingRope(120) << endl;
    cout << "---------------------" << endl;
    return 0;
}
