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
    int binary_search(vector<int>& nums, int target)
    {
        int ptr1 = 0;
        int ptr2 = nums.size() - 1;

        while (ptr1 <= ptr2)
        {
            int mid = ptr1 + (ptr2 - ptr1) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                ptr1 = mid + 1;
            else
                ptr2 = mid - 1;
        }
        return -1;
    }

    int binary_left_boundary(vector<int>& nums, int target)
    {
        int ptr1 = 0;
        int ptr2 = nums.size() - 1;

        while (ptr1 < ptr2)
        {
            int mid = ptr1 + (ptr2 - ptr1) / 2;
            if (nums[mid] < target)
                ptr1 = mid + 1;
            else
                ptr2 = mid;
        }

        return ptr1;
    }

    int binary_right_boundary(vector<int>& nums, int target)
    {
        int ptr1 = 0;
        int ptr2 = nums.size() - 1;

        while (ptr1 < ptr2)
        {
            int mid = ptr1 + (ptr2 - ptr1) / 2;
            if (nums[mid] == target)
                ptr1 = mid + 1;
            else if (nums[mid] < target)
                ptr1 = mid + 1;
            else if (target < nums[mid])
                ptr2 = mid - 1;
        }
        return ptr2;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {0, 1, 2, 3, 3, 5, 6, 7, 8};
    int target = 3;

//    cout << s.binary_search(nums, target) << endl;
//    cout << s.binary_left_boundary(nums, target) << endl;
    cout << s.binary_right_boundary(nums, target) << endl;

    cout << "---------------------" << endl;
    return 0;
}
