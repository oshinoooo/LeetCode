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
    int integerReplacement(int n)
    {
        int count = 0;
        while (n % 2 == 0)
        {
            ++count;
            n /= 2;
        }

        if (n == 1)
            return count;

        return count + 2 + min(integerReplacement(n / 2 + 1), integerReplacement(n / 2));
    }

    int integerReplacement2(int n)
    {
        if (n == 1)
            return 0;

        if (memo.count(n))
            return memo[n];

        if (n % 2 == 0)
            return memo[n] = 1 + integerReplacement(n / 2);

        return memo[n] = 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
    }
private:
    unordered_map<int, int> memo;
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.integerReplacement(2147483647) << endl;
    cout << "---------------------" << endl;
    return 0;
}
