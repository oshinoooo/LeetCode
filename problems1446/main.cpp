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
    int maxPower(string s)
    {
        int max_count = 1;
        int count = 1;
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i - 1] == s[i])
            {
                ++count;
                max_count = max(max_count, count);
            }
            else
                count = 1;
        }

        return max_count;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    cout << s.maxPower("abbcccddddeeeeedcba") << endl;
    cout << "---------------------" << endl;
    return 0;
}
