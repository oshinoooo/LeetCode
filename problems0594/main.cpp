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
    int findLHS(vector<int>& nums)
    {
        map<int, int> m;
        for (auto& num : nums)
            ++m[num];

        int max_length = 0;
        auto pre = m.begin();
        auto cur = ++m.begin();
        while (cur != m.end())
        {
            if (abs(pre->first - cur->first) == 1)
                max_length = max(max_length, pre->second + cur->second);
            ++pre;
            ++cur;
        }

        return max_length;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1,3,2,2,5,2,3,7};
    cout << s.findLHS(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
