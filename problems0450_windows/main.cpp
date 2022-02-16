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
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if (root == nullptr)
            return nullptr;

        if (root->val < key)
            root->right = deleteNode(root->right, key);
        else if (key < root->val)
            root->left = deleteNode(root->left, key);
        else
        {
            if (root->left == nullptr)
                return root->right;
            else if (root->right == nullptr)
                return root->left;
            else
            {
                TreeNode* cur = root->right;
                while (cur->left)
                    cur = cur->left;
                cur->left = root->left;
                root = root->right;
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
    TreeNode* n1 = new TreeNode(4);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(6);
    TreeNode* n4 = new TreeNode(1);
    TreeNode* n5 = new TreeNode(3);
    TreeNode* n6 = new TreeNode(5);
    TreeNode* n7 = new TreeNode(7);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    s.deleteNode(n1, 2);

    DLR(n1);
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
