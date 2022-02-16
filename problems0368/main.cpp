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
    vector<int> largestDivisibleSubset(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        vector<int> out;
        vector<int> tmp;

        


        return out;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1, 2, 4, 8};
    vector<int> out = s.largestDivisibleSubset(nums);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
