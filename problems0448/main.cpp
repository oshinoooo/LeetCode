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
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != i + 1 && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
                --i;
            }
        }

        vector<int> out;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != i + 1)
                out.push_back(i + 1);
        }
        return out;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> out = s.findDisappearedNumbers(nums);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
