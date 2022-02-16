#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return createTree(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* createTree(vector<int>& nums, int left, int right)
    {
        if (left > right)
            return nullptr;

        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = createTree(nums, left, mid - 1);
        node->right = createTree(nums, mid + 1, right);
        return node;
    }
};

int main()
{
    cout << "-----------------------" << endl;
    Solution s;
    vector<int> in = {-10,-3,0,5,9};
    TreeNode* out = s.sortedArrayToBST(in);
    cout << "-----------------------" << endl;
    return 0;
}
