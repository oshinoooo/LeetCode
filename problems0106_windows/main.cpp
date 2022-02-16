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
    TreeNode* buildTree1(vector<int>& inorder, vector<int>& postorder)
    {
        if (inorder.empty())
            return nullptr;

        int cur = postorder.back();
        postorder.pop_back();
        TreeNode* root = new TreeNode(cur);

        for (int i = 0; i < inorder.size(); ++i)
        {
            if (inorder[i] == cur)
            {
                vector<int> left_inorder(inorder.begin(), inorder.begin() + i);
                vector<int> right_inorder(inorder.begin() + i + 1, inorder.end());

                vector<int> left_postorder(postorder.begin(), postorder.begin() + i);
                vector<int> right_postorder(postorder.begin() + i, postorder.end());

                root->left = buildTree(left_inorder, left_postorder);
                root->right = buildTree(right_inorder, right_postorder);
                break;
            }
        }

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        return my_buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

private:
    TreeNode* my_buildTree(vector<int>& inorder, vector<int>& postorder, int in_le, int in_ri, int po_le, int po_ri)
    {
        if (in_ri < in_le)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[po_ri]);

        for (int i = in_le; i <= in_ri; ++i)
        {
            if (inorder[i] == postorder[po_ri])
            {
                root->left = my_buildTree(inorder, postorder, in_le, i - 1, po_le, po_le + i - 1 - in_le);
                root->right = my_buildTree(inorder, postorder, i + 1, in_ri, po_le + i - in_le, po_ri - 1);
                break;
            }
        }

        return root;
    }
};

void DLR(TreeNode* root)
{
    if (root == nullptr)
        return;
    cout << root->val << " ";
    DLR(root->left);
    DLR(root->right);
}

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    vector<int> inorder   = {9,  3, 15, 20, 7};
    vector<int> postorder = {9, 15,  7, 20, 3};
    TreeNode* n0 = s.buildTree(inorder, postorder);
    DLR(n0);
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
