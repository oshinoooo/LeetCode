#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int ptr1 = 0;
        int ptr2 = nums.size() - 1;
        while (ptr1 <= ptr2)
        {
            int mid = (ptr1 + ptr2) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                ptr1 = mid + 1;
            else
                ptr2 = mid - 1;
        }
        return -1;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 2;
    cout << s.search(nums, target) << endl;
    cout << "---------------------" << endl;
    return 0;
}
