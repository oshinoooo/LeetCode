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
    int translateNum(int num)
    {
        string sep = to_string(num);
        vector<int> dp = {1, 1};
        for (int i = 1; i < sep.size(); ++i)
        {
            if (sep[i - 1] != '0' && (sep[i - 1] - '0') * 10 + (sep[i] - '0') <= 25)
                dp.push_back(dp[i] + dp[i - 1]);
            else
                dp.push_back(dp[i]);
        }
        return dp.back();
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.translateNum(506) << endl;
    cout << "---------------------" << endl;
    return 0;
}
