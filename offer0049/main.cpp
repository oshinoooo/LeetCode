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
    int nthUglyNumber(int n)
    {
        vector<int> dp = {1};

        auto ptr2 = 0;
        auto ptr3 = 0;
        auto ptr5 = 0;

        while (dp.size() < n)
        {
            int tmp2 = dp[ptr2] * 2;
            int tmp3 = dp[ptr3] * 3;
            int tmp5 = dp[ptr5] * 5;

            if (dp.back() == tmp2)
            {
                ++ptr2;
                continue;
            }

            if (dp.back() == tmp3)
            {
                ++ptr3;
                continue;
            }

            if (dp.back() == tmp5)
            {
                ++ptr5;
                continue;
            }

            if (tmp2 <= tmp3 && tmp2 <= tmp5)
            {
                dp.push_back(tmp2);
                ++ptr2;
            }
            else if (tmp3 <= tmp2 && tmp3 <= tmp5)
            {
                dp.push_back(tmp3);
                ++ptr3;
            }
            else if (tmp5 <= tmp3 && tmp5 <= tmp2)
            {
                dp.push_back(tmp5);
                ++ptr5;
            }
        }

        return dp.back();
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.nthUglyNumber(10) << endl;
    cout << "---------------------" << endl;
    return 0;
}
