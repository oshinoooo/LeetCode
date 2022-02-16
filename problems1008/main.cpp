#include <iostream>
#include <vector>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

class Solution
{
public:
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        reverse(preorder.begin(), preorder.end());
        stack<int> mid;
        mid.push(INT_MAX);
        return construct(preorder, mid);
    }

    TreeNode* construct(vector<int>& preorder, stack<int>& mid)
    {
        TreeNode* root = new TreeNode(preorder.back());
        mid.push(preorder.back());
        preorder.pop_back();

        if (!preorder.empty() && preorder.back() < mid.top())
            root->left = construct(preorder, mid);

        mid.pop();

        if (!preorder.empty() && preorder.back() < mid.top())
            root->right = construct(preorder, mid);

        return root;
    }

    void DLR(TreeNode* root)
    {
        if (root == nullptr)
            return;
        cout << root->val << " ";
        DLR(root->left);
        DLR(root->right);
    }
};

int main()
{
    cout << "-----------------" << endl;
    Solution s;
    vector<int> preorder = {8,5,1,7,10,12};
    s.DLR(s.bstFromPreorder(preorder));
    cout << endl;
    cout << "-----------------" << endl;
    return 0;
}
