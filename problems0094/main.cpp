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
    vector<int> inorderTraversal(TreeNode* root)
    {
        if (root == nullptr)
            return {};

        vector<int> out;
        vector<int> tmp;

        tmp = inorderTraversal(root->left);
        out.insert(out.end(), tmp.begin(), tmp.end());

        out.push_back(root->val);

        tmp = inorderTraversal(root->right);
        out.insert(out.end(), tmp.begin(), tmp.end());

        return out;
    }

    vector<int> inorderTraversal2(TreeNode* root)
    {
        vector<int> nums;
        LDR(root, nums);
        return nums;
    }

    void LDR(TreeNode* root, vector<int>& nums)
    {
        if (root == nullptr)
            return;
        LDR(root->left, nums);
        nums.push_back(root->val);
        LDR(root->right, nums);
    }
};

int main()
{
    cout << "-------------------------" << endl;
    Solution s;
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    vector<int> out = s.inorderTraversal(n1);

    for (auto o : out)
        cout << o << endl;
    cout << "-------------------------" << endl;
    return 0;
}
