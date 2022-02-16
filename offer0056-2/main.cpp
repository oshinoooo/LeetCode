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
    int singleNumber1(vector<int>& nums)
    {
        vector<int> count(31, 0);
        for (auto& num : nums)
        {
            for (int i = 0; i < 31; ++i)
            {
                int flag = pow(2, i);

                if (num < flag)
                    break;

                if (num & flag)
                    count[i] += 1;
            }
        }

        int out = 0;
        for (int i = 0; i < count.size(); ++i)
            out += count[i] % 3 << i;
        return out;
    }

    int singleNumber2(vector<int>& nums)
    {
        int ones = 0;
        int twos = 0;
        for(auto& num : nums)
        {
            ones = ones ^ num & ~twos;
            twos = twos ^ num & ~ones;
        }
        return ones;
    }

    int singleNumber(vector<int>& nums)
    {
        unordered_map<int, int> m;
        for (auto& num : nums)
            ++m[num];
        for (auto& num : m)
        {
            if (num.second == 1)
                return num.first;
        }
        return -1;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {9, 1, 7, 9, 7, 9, 7};
    cout << s.singleNumber(nums) << endl;
    cout << "---------------------" << endl;
    return 0;
}
