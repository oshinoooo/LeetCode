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
    int minDepth(TreeNode* root)
    {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return 1;
        int min_depth = INT_MAX;
        if (root->left != nullptr) min_depth = min(minDepth(root->left), min_depth);
        if (root->right != nullptr) min_depth = min(minDepth(root->right), min_depth);
        return min_depth + 1;
    }
};

int main()
{
    cout << "----------------"<< endl;
    Solution s;
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(1);
    TreeNode* n3 = new TreeNode(1);
    TreeNode* n4 = new TreeNode(1);
    TreeNode* n5 = new TreeNode(1);
    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;
    cout << s.minDepth(n1) << endl;
    cout << "----------------"<< endl;
    return 0;
}
