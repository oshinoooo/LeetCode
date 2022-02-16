#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void ldrIterate(TreeNode* root) {
        stack<TreeNode*> stk;
        while (root) {
            stk.push(root);
            root = root->left;
        }

        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();

            if (!node)
                continue;

            cout << node->val << " ";

            node = node->right;
            while (node) {
                stk.push(node);
                node = node->left;
            }
        }
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
    s.ldrIterate(n1);
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
