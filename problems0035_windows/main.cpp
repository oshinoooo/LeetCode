#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int ans = nums.size();

        while (left <= right)
        {
            int mid = (right + left) / 2;
            if (target <= nums[mid])
            {
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return ans;
    }
};

int main()
{
    cout << "-----------------------" << endl;
    Solution s;
    vector<int> nums = {1, 3, 5, 6};
    int target = 7;
    cout << s.searchInsert(nums, target) << endl;
    cout << "-----------------------" << endl;
    return 0;
}
