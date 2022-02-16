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
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        vector<TreeNode*> tmp_path;
        vector<vector<TreeNode*>> paths;
        test(root, p, q, tmp_path, paths);

        int i = 0;
        int length = min(paths[0].size(), paths[1].size());
        while (i < length && paths[0][i] == paths[1][i])
            ++i;
        return paths[0][i - 1];
    }

private:
    void test(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*>& tmp_path, vector<vector<TreeNode*>>& paths)
    {
        if (!root || paths.size() == 2)
            return;

        tmp_path.push_back(root);
        if (root == p || root == q)
            paths.push_back(tmp_path);
        test(root->left, p, q, tmp_path, paths);
        test(root->right, p, q, tmp_path, paths);
        tmp_path.pop_back();
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        dfs(root, p, q);
        return ans;
    }

private:
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root)
            return false;

        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if ((lson && rson) || ((root == p || root == q) && (lson || rson)))
            ans = root;
        return lson || rson || (root == p || root == q);
    }

private:
    TreeNode* ans;
};

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

    TreeNode* n0 = s.lowestCommonAncestor(n1, n4, n7);
    cout << n0->val << endl;
    cout << "---------------------" << endl;
    return 0;
}