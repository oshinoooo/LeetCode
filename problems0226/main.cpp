#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

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
    TreeNode* invertTree(TreeNode* root)
    {
        if (root == nullptr)
            return nullptr;

        TreeNode* tmp_left = invertTree(root->right);
        TreeNode* tmp_right = invertTree(root->left);
        root->left = tmp_left;
        root->right = tmp_right;
        return root;
    }

    void LDR(TreeNode* root)
    {
        if (root == nullptr)
            return;
        LDR(root->left);
        cout << root->val << " ";
        LDR(root->right);
    }
};

int main()
{
    cout << "---------------------" << endl;
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

    TreeNode* n0 = s.invertTree(n1);
    s.LDR(n0);
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
