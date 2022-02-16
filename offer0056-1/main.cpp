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
    vector<int> singleNumbers(vector<int>& nums)
    {
        int result = 0;
        for (auto& num : nums)
            result ^= num;

        int flag = 1;
        while ((result & flag) == 0)
            flag <<= 1;

        int a = 0;
        int b = 0;
        for (auto& num : nums)
        {
            if (num & flag)
                a ^= num;
            else
                b ^= num;
        }

        return {a, b};
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1,2,10,4,1,4,3,3};
    vector<int> out = s.singleNumbers(nums);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
