#include <iostream>
#include <vector>
#include <set>

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
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> out;
        LRD(root, out);
        return out;
    }

private:
    void LRD(TreeNode* root, vector<int>& out)
    {
        if (root == nullptr) return;
        LRD(root->left, out);
        LRD(root->right, out);
        out.push_back(root->val);
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

    vector<int> out = s.postorderTraversal(n1);
    for (auto o : out)
        cout << o << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
