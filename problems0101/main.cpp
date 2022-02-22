#include <iostream>
#include <vector>
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
    bool isSymmetric1(TreeNode* root) {
        return myIsSymmetric(root, root);
    }

    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        que.push(root);

        while (!que.empty()) {
            TreeNode* left = que.front();
            que.pop();

            TreeNode* right = que.front();
            que.pop();

            if (!left && !right)
                continue;

            if (!left || !right || left->val != right->val)
                return false;

            que.push(left->left);
            que.push(right->right);
            que.push(left->right);
            que.push(right->left);
        }

        return true;
    }

private:
    bool myIsSymmetric(TreeNode* left, TreeNode* right) {
        if (!left && !right)
            return true;

        if (!left || !right || left->val != right->val)
            return false;

        return myIsSymmetric(left->left, right->right) && myIsSymmetric(left->right, right->left);
    }
};

int main() {
    cout << "-------------------" << endl;
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(2);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(5);
    TreeNode* n7 = new TreeNode(4);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    Solution s;
    cout << s.isSymmetric(n1) << endl;
    cout << "-------------------" << endl;
    return 0;
}
