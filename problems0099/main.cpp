#include <iostream>
#include <vector>
#include <algorithm>
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
    void recoverTree(TreeNode* root)
    {
        if (root == nullptr) return;
        vector<int> nums;
        get(root, nums);
        sort(nums.begin(), nums.end(), [&](int x, int y){return x > y;});
        fix(root, nums);
    }

    void ldr_non_recursive(TreeNode* root, vector<int>& nums)
    {
        if (root == nullptr) return;
        stack<TreeNode*> sta;
        sta.push(root);

        while (!sta.empty())
        {
            while (sta.top() != nullptr)
                sta.push(sta.top()->left);

            sta.pop();
            if (sta.empty())
                break;
            nums.push_back(sta.top()->val);
            TreeNode* tmp = sta.top()->right;
            sta.pop();
            sta.push(tmp);
        }
    }

private:
    void get(TreeNode* root, vector<int>& nums)
    {
        if (root == nullptr) return;
        get(root->left, nums);
        nums.push_back(root->val);
        get(root->right, nums);
    }

    void fix(TreeNode* root, vector<int>& nums)
    {
        if (root == nullptr) return;
        fix(root->left, nums);
        root->val = nums[nums.size() - 1];
        nums.pop_back();
        fix(root->right, nums);
    }
};

int main()
{
    cout << "------------------" << endl;
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

    vector<int> nums;
    s.ldr_non_recursive(n1, nums);
    for (auto num : nums)
        cout << num << " ";
    cout << endl;
    s.recoverTree(n1);
    cout << "------------------" << endl;
    return 0;
}