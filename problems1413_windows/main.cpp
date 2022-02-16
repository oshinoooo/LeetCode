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
    int minStartValue(vector<int>& nums)
    {
        int startValue = 1;
        int sum = startValue;
        for (auto& num : nums)
        {
            sum += num;
            if (sum < 1)
            {
                startValue += 1 - sum;
                sum = 1;
            }
        }
        return startValue;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1, 2};
    cout << s.minStartValue(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
