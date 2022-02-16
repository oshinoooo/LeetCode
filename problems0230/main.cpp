#include <iostream>
#include <vector>
#include <map>
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
    int kthSmallest(TreeNode* root, int k)
    {
        vector<int> nums;
        DLR(root, nums, k);
        return nums.back();
    }

private:
    void DLR(TreeNode* root, vector<int>& nums, int k)
    {
        if (root == nullptr)
            return;

        DLR(root->left, nums, k);
        if (nums.size() == k)
            return;
        nums.push_back(root->val);
        DLR(root->right, nums, k);
    }
};

int main()
{
    cout << "-----------------" << endl;
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

    int k = 3;
    cout << s.kthSmallest(n1, k) << endl;
    cout << "-----------------" << endl;
    return 0;
}
