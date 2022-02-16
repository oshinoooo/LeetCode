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
    int removeDuplicates(vector<int>& nums)
    {
        int cur = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            int tail = i;
            if (nums[cur] != nums[tail])
            {
                nums[cur + 1] = nums[tail];
            }
        }
    }
};

int main()
{
    cout << "-----------------------" << endl;
    Solution s;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << s.removeDuplicates(nums) << endl;
    cout << "-----------------------" << endl;
    return 0;
}
