#include <iostream>
#include <vector>
#include <stack>
#include <queue>

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

// 二叉树遍历
class Solution_Binary_Tree
{
public:
    // 前序遍历
    void DLR_Recursive(TreeNode* tree)
    {
        if (tree != nullptr)
        {
            cout << tree->val << " ";
            DLR_Recursive(tree->left);
            DLR_Recursive(tree->right);
        }
    }

    void DLR_Non_Recursive(TreeNode* tree)
    {
        stack<TreeNode*> sta;
        while (tree != nullptr || !sta.empty())
        {
            if (tree != nullptr)
            {
                cout << tree->val << " ";
                sta.push(tree->right);
                tree = tree->left;
            }
            else
            {
                tree = sta.top();
                sta.pop();
            }
        }
    }

    // 中序遍历
    void LDR_Recursive(TreeNode* tree)
    {
        if (tree != nullptr)
        {
            LDR_Recursive(tree->left);
            cout << tree->val << " ";
            LDR_Recursive(tree->right);
        }
    }

    void LDR_Non_Recursive(TreeNode* tree)
    {
        stack<TreeNode*> sta;
        while (tree != nullptr || !sta.empty())
        {
            if (tree != nullptr)
            {
                sta.push(tree);
                tree = tree->left;
            }
            else
            {
                tree = sta.top();
                sta.pop();
                cout << tree->val << " ";
                tree = tree->right;
            }
        }
    }

    // 后序遍历
    void LRD_Recursive(TreeNode* tree)
    {
        if (tree != nullptr)
        {
            LRD_Recursive(tree->left);
            LRD_Recursive(tree->right);
            cout << tree->val << " ";
        }
    }

    void LRD_Non_Recursive(TreeNode* tree)
    {
        stack<TreeNode*> sta;
        stack<int> tag;

        while (tree != nullptr || !sta.empty())
        {
            while (tree != nullptr)
            {
                sta.push(tree);
                tag.push(0);
                tree = tree->left;
            }

            if (!sta.empty())
            {
                if (tag.top() == 1)
                {
                    tree = sta.top();
                    cout << tree->val << endl;
                    sta.pop();
                    tag.pop();
                }
                else
                {
                    tree = sta.top();
                    if (!sta.empty())
                    {
                        tree = tree->right;
                        tag.pop();
                        tag.push(1);
                    }
                    sta.pop();
                }
            }
        }
    }
};

// 二叉排序树
class Solution_Binary_Search_Tree
{
public:
    // 插入
    bool BST_Insert(TreeNode** tree, int key)
    {
        if (*tree == nullptr)
        {
            *tree = new TreeNode(key);
            return true;
        }
        else if ((*tree)->val == key)
            return false;
        else if ((*tree)->val > key)
            return BST_Insert(&((*tree)->left), key);
        else if ((*tree)->val < key)
            return BST_Insert(&((*tree)->right), key);
    }

    // 查找
    TreeNode* BST_Find(TreeNode** tree, int key)
    {
        if (*tree == nullptr)
            return nullptr;

        while (*tree != nullptr && (*tree)->val != key)
        {
            if ((*tree)->val > key)
                *tree = (*tree)->left;
            else
                *tree = (*tree)->right;
        }
        return *tree;
    }

    TreeNode* BST_Find_Recursive(TreeNode** tree, int key)
    {
        if (*tree == nullptr)
            return nullptr;
        else if ((*tree)->val == key)
            return *tree;
        else if ((*tree)->val > key)
            return BST_Find_Recursive(&(*tree)->left, key);
        else if ((*tree)->val < key)
            return BST_Find_Recursive(&(*tree)->right, key);
    }

    // 删除
    bool BST_Delete(TreeNode** tree, int key)
    {
        if (*tree == nullptr)
            return false;

        TreeNode* del = *tree;
        TreeNode* parent = nullptr;
        int flag = -1;

        while (del != nullptr && del->val != key)
        {
            parent = del;
            if (del->val > key)
            {
                del = del->left;
                flag = 0;
            }
            else
            {
                del = del->right;
                flag = 1;
            }
        }

        if (del == nullptr)
            return false;

        // 有左有右
        if (del->left != nullptr && del->right != nullptr)
        {
            TreeNode* tmp = del->right;
            parent = del;
            while (tmp->left != nullptr)
            {
                parent = tmp;
                tmp = tmp->left;
            }
            del->val = tmp->val;
            del = tmp;
            flag = 0;
        }

        // 根
        if (parent == nullptr)
            parent = *tree;

        // 无左无右
        if (del->left == nullptr && del->right == nullptr)
        {
            if (flag == 0)
                parent->left = nullptr;
            else if (flag == 1)
                parent->right = nullptr;
        }
        else
        {
            if (flag == 0)
                parent->left = del->right ? del->right : del->left;
            else if (flag == 1)
                parent->right = del->right ? del->right : del->left;
        }

        delete del;
        return true;
    }

    // 广度优先遍历
    void BFS(TreeNode* tree)
    {
        queue<TreeNode*> que;
        que.push(tree);

        while (!que.empty())
        {
            if (que.front() == nullptr)
                que.pop();
            else
            {
                cout << que.front()->val << " ";
                que.push(que.front()->left);
                que.push(que.front()->right);
                que.pop();
            }
        }
    }

    // 深度优先遍历
    void DFS(TreeNode* tree)
    {
        stack<TreeNode*> sta;
        sta.push(tree);

        while (!sta.empty())
        {
            if (sta.top() == nullptr)
            {
                sta.pop();
            }
            else
            {
                TreeNode* node = sta.top();
                sta.pop();
                while (node != nullptr)
                {
                    cout << node->val << " ";
                    if (node->right != nullptr)
                        sta.push(node->right);
                    node = node->left;
                }

            }
        }
    }
};

int Test_Binary_Tree()
{
    cout << "------------------" << endl;
    Solution_Binary_Tree s;
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

    // 前序遍历
    s.DLR_Recursive(n1);
    cout << "\n------------------" << endl;
    s.DLR_Non_Recursive(n1);
    cout << "\n------------------" << endl;

    // 中序遍历
    s.LDR_Recursive(n1);
    cout << "\n------------------" << endl;
    s.LDR_Non_Recursive(n1);
    cout << "\n------------------" << endl;

    // 后序遍历
    s.LRD_Recursive(n1);
    cout << "\n------------------" << endl;
    s.LRD_Non_Recursive(n1);
    cout << "\n------------------" << endl;
    return 0;
}

int Test_Binary_Search_Tree()
{
    cout << "------------------" << endl;
    Solution_Binary_Search_Tree s;

    TreeNode* tree = nullptr;
    cout << s.BST_Insert(&tree, 4) << " ";
    cout << s.BST_Insert(&tree, 2) << " ";
    cout << s.BST_Insert(&tree, 1) << " ";
    cout << s.BST_Insert(&tree, 3) << " ";
    cout << s.BST_Insert(&tree, 6) << " ";
    cout << s.BST_Insert(&tree, 5) << " ";
    cout << s.BST_Insert(&tree, 7) << endl;
    cout << "------------------" << endl;
    cout << s.BST_Find(&tree, 4)->val << endl;
    cout << "------------------" << endl;
    cout << s.BST_Find_Recursive(&tree, 4)->val << endl;
//    cout << "------------------" << endl;
//    cout << s.BST_Delete(&tree, 4) << endl;
//    cout << s.BST_Delete(&tree, 2) << endl;
//    cout << s.BST_Delete(&tree, 3) << endl;
//    cout << s.BST_Delete(&tree, 1) << endl;
//    cout << s.BST_Delete(&tree, 1) << endl;
    cout << "------------------" << endl;
    s.BFS(tree);
    cout << endl;
    cout << "------------------" << endl;
    s.DFS(tree);
    cout << endl;
    cout << "------------------" << endl;
}

int main()
{
    cout << "------------------" << endl;
//    Test_Binary_Tree();
    Test_Binary_Search_Tree();
    cout << "------------------" << endl;
    return 0;
}
