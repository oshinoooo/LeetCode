#include <iostream>
#include <vector>

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
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if (root == nullptr)
            return false;

        if (root->left == nullptr && root->right == nullptr)
            return root->val == targetSum;
        else if (root->left != nullptr && root->right == nullptr)
            return hasPathSum(root->left, targetSum - root->val);
        else if (root->left == nullptr && root->right != nullptr)
            return hasPathSum(root->right, targetSum - root->val);
        else
            return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

int main()
{
    cout << "----------------"<< endl;
    Solution s;
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n7 = new TreeNode(7);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    cout << s.hasPathSum(n1, 11) << endl;
    cout << "----------------"<< endl;
    return 0;
}
