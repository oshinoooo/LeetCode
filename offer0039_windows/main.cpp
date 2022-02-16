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
    int majorityElement(vector<int>& nums)
    {
        unordered_map<int, int> m;
        for (auto& num : nums)
        {
            if (nums.size() / 2 < ++m[num])
                return num;
        }
        return 0;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    cout << s.majorityElement(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
