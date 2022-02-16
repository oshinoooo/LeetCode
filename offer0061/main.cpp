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
    bool isStraight(vector<int>& nums)
    {
        set<int> s;
        int count_0 = 0;
        for (auto& num : nums)
        {
            if (num != 0)
                s.insert(num);
            else
                ++count_0;
        }

        if (s.size() + count_0 != 5 || *s.rbegin() - *s.begin() > 4)
            return false;

        return true;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << s.isStraight(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
