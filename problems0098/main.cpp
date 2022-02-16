#include <iostream>
#include <vector>
#include <stack>

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
    bool isValidBST(TreeNode* root)
    {
        return helper(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST2(TreeNode* root)
    {
        if (root == nullptr) return true;

        if (!isValidBST(root->left))
            return false;

        if (root->val <= pre)
            return false;

        pre = root->val;

        return isValidBST(root->right);
    }

private:
    int pre = INT_MIN;
    bool helper(TreeNode* root, long long lower, long long upper)
    {
        if (root == nullptr) return true;
        if (root->val <= lower || root->val >= upper) return false;
        return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
    }
};

int main()
{
    cout << "-------------------" << endl;
    Solution s;
    TreeNode* n1 = new TreeNode(0);
//    TreeNode* n2 = new TreeNode(2);
//    TreeNode* n3 = new TreeNode(2);
//    TreeNode* n4 = new TreeNode(4);
//    TreeNode* n5 = new TreeNode(5);
//    TreeNode* n6 = new TreeNode(5);
//    TreeNode* n7 = new TreeNode(4);
//    n1->left = n2;
//    n1->right = n3;
//    n2->left = n4;
//    n2->right = n5;
//    n3->left = n6;
//    n3->right = n7;

    cout << s.isValidBST2(n1) << endl;
    cout << "-------------------" << endl;
    return 0;
}
