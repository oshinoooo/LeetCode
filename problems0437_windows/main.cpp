#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

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
    int pathSum1(TreeNode* root, int targetSum)
    {
        if (root == nullptr)
            return 0;

        int ret = rootSum(root, targetSum);
        ret += pathSum1(root->left, targetSum);
        ret += pathSum1(root->right, targetSum);
        return ret;
    }

private:
    int rootSum(TreeNode* root, int targetSum)
    {
        if (root == nullptr)
            return 0;

        int ret = 0;
        if (root->val == targetSum)
            ret++;

        ret += rootSum(root->left, targetSum - root->val);
        ret += rootSum(root->right, targetSum - root->val);
        return ret;
    }

    // --------------------------------------------------------------

public:
    int pathSum2(TreeNode* root, int targetSum)
    {
        prefix[0] = 1;
        return DFS(root, 0, targetSum);
    }

private:
    int DFS(TreeNode *root, long long curr, int targetSum)
    {
        if (!root)
            return 0;

        int ret = 0;
        curr += root->val;
        if (prefix.count(curr - targetSum))
            ret = prefix[curr - targetSum];

        prefix[curr]++;
        ret += DFS(root->left, curr, targetSum);
        ret += DFS(root->right, curr, targetSum);
        prefix[curr]--;

        return ret;
    }

private:
    unordered_map<long long, int> prefix;

    // --------------------------------------------------------------

    void DFS(TreeNode* root)
    {
        stack<TreeNode*> sta;
        sta.push(root);

        while (!sta.empty())
        {
            TreeNode* tmp = sta.top();
            sta.pop();

            while (tmp != nullptr)
            {
                cout << tmp->val << " ";
                if (tmp->right != nullptr)
                    sta.push(tmp->right);
                tmp = tmp->left;
            }
        }
        cout << endl;
    }
};

int main()
{
    cout << "---------------" << endl;
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

    int targetSum = 6;
//    s.DFS(n1);
//    cout << s.pathSum1(n1, targetSum) << endl;
    cout << s.pathSum2(n1, targetSum) << endl;
    cout << "---------------" << endl;
    return 0;
}
