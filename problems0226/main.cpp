#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void showTree(TreeNode* root) {
    if (root == nullptr) return;
    showTree(root->left);
    cout << root->val << " ";
    showTree(root->right);
}

class Solution {
public:
    TreeNode* invertTree1(TreeNode* root) {
        if (!root) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    TreeNode* invertTree2(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();

            if (node) {
                swap(node->left, node->right);
                que.push(node->left);
                que.push(node->right);
            }
        }

        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();

            if (node) {
                stk.push(node->left);
                stk.push(node->right);
                swap(node->left, node->right);
            }
        }

        return root;
    }
};

int main() {
    cout << "---------------------" << endl;
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

    Solution s;
    TreeNode* n0 = s.invertTree(n1);
    showTree(n0);
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
