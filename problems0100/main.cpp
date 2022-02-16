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
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        else if (p == nullptr || q == nullptr)
            return false;
        else if (p->val != q->val)
            return false;
        else
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main()
{
    cout << "----------------" << endl;
    TreeNode * n1 = new TreeNode(1);
    TreeNode * n2 = new TreeNode(2);
    TreeNode * n3 = new TreeNode(3);
    TreeNode * n4 = new TreeNode(1);
    TreeNode * n5 = new TreeNode(2);
    TreeNode * n6 = new TreeNode(3);
    n1->left = n2;
    n1->right = n3;
    n4->left = n5;
    n4->right = n6;

    Solution s;
    cout << s.isSameTree(n1, n4) << endl;
    cout << "----------------" << endl;
    return 0;
}
