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

using namespace std;

class Solution1
{
public:
    vector<TreeNode*> generateTrees(int n)
    {
        vector<int> in;
        for (int i = 1; i <= n; ++i)
            in.push_back(i);
        vector<vector<int>> permutation;
        Permutation(in, 0, in.size(), permutation);

        vector<TreeNode*> all_tree;
        for (auto per : permutation)
            all_tree.push_back(build(per));

        vector<vector<TreeNode*>> all_traverse;
        for (auto all : all_tree)
        {
            vector<TreeNode*> tmp;
            LDR(all, tmp);
            all_traverse.push_back(tmp);
        }

        vector<TreeNode*> out;
        for (auto all : all_traverse)
            out.push_back(all[0]);

        return out;
    }

    void Permutation(vector<int>& in, int start, int end, vector<vector<int>>& result)
    {
        if (start == end)
        {
            vector<int> res;
            for(int i = 0; i < end; i++)
                res.push_back(in[i]);
            result.push_back(res);
            return;
        }

        for (int i = start; i < end; i++)
        {
            swap(in[start], in[i]);
            Permutation(in, start+1, end, result);
            swap(in[i], in[start]);
        }
    }

    TreeNode* build(vector<int> array)
    {
        TreeNode* root = nullptr;
        for (auto value : array)
            insert(root, value);
        return root;
    }

    void insert(TreeNode*& root, int value)
    {
        if (root == nullptr)
            root = new TreeNode(value);
        else if (value < root->val)
            insert(root->left, value);
        else
            insert(root->right, value);
    }

    void LDR(TreeNode* tree, vector<TreeNode*>& out)
    {
        if (tree == nullptr)
            return;
        LDR(tree->left, out);
        out.push_back(tree);
        LDR(tree->right, out);
    }
};

class Solution2
{
public:
    vector<TreeNode*> generateTrees(int n)
    {
        if (n == 0) return {nullptr};
        return generateTrees(1, n);
    }

private:
    vector<TreeNode*> generateTrees(int start, int end)
    {
        if (start > end) return {nullptr};

        vector<TreeNode*> allTrees;

        for (int i = start; i <= end; i++)
        {
            // 获得所有可行的左子树集合
            vector<TreeNode*> leftTrees = generateTrees(start, i - 1);

            // 获得所有可行的右子树集合
            vector<TreeNode*> rightTrees = generateTrees(i + 1, end);

            // 从左子树集合中选出一棵左子树，从右子树集合中选出一棵右子树，拼接到根节点上
            for (auto& left : leftTrees)
            {
                for (auto& right : rightTrees)
                {
                    TreeNode* currTree = new TreeNode(i);
                    currTree->left = left;
                    currTree->right = right;
                    allTrees.emplace_back(currTree);
                }
            }
        }
        return allTrees;
    }
};

class Solution3
{
public:
    vector<TreeNode*> generateTrees(int n)
    {
        if (n == 0) return {nullptr};
        return build(1, n);
    }

    vector<TreeNode*> build(int left, int right)
    {
        if (left > right)
            return {nullptr};

        vector<TreeNode*> all_trees;

        for (int i = left; i <= right; ++i)
        {
            vector<TreeNode*> left_trees = build(left, i - 1);
            vector<TreeNode*> right_trees = build(i + 1, right);

            for (auto& left_tree : left_trees)
            {
                for (auto& right_tree : right_trees)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = left_tree;
                    root->right = right_tree;
                    all_trees.emplace_back(root);
                }
            }
        }

        return all_trees;
    }
};

void dlr(TreeNode* tree)
{
    if (tree == nullptr)
    {
        cout << "null ";
        return;
    }

    dlr(tree->left);
    cout << tree->val << " ";
    dlr(tree->right);
}

int main()
{
    cout << "-------------------------" << endl;
    Solution2 s;
    vector<TreeNode*> out = s.generateTrees(3);
    for (auto o : out)
    {
        dlr(o);
        cout << "\n-------------" << endl;
    }
    cout << "-------------------------" << endl;
    return 0;
}
