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
    int searchInsert(vector<int>& nums, int target)
    {
        int ptr1 = 0;
        int ptr2 = nums.size() - 1;

        while (ptr1 <= ptr2)
        {
            int mid = ptr1 + (ptr2 - ptr1) / 2;

            if (nums[mid] < target)
                ptr1 = mid + 1;
            else
                ptr2 = mid - 1;
        }

        return ptr1;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {1, 3, 5, 5, 5, 5, 5, 6};
    int target = 5;
    cout << s.searchInsert(nums, target) << endl;
    cout << "---------------------" << endl;
    return 0;
}
