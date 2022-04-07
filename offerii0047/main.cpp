#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right) : val(_val), left(_left), right(_right) {}
};

void showTree(TreeNode* root) {
    if (!root) return;
    showTree(root->left);
    cout << root->val << " ";
    showTree(root->right);
}

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        return myPruneTree(root);
    }

private:
    TreeNode* myPruneTree(TreeNode*& root) {
        if (!root)
            return nullptr;

        myPruneTree(root->left);
        myPruneTree(root->right);

        if (!root->left && !root->right && root->val == 0) {
            delete root;
            root = nullptr;
        }

        return root;
    }
};

int main() {
    cout << "---------------------" << endl;
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(0);
    TreeNode* n3 = new TreeNode(1);
    TreeNode* n4 = new TreeNode(0);
    TreeNode* n5 = new TreeNode(0);
    TreeNode* n6 = new TreeNode(0);
    TreeNode* n7 = new TreeNode(1);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    showTree(n1);
    cout << endl;

    Solution s;
    TreeNode* n0 = s.pruneTree(n1);

    showTree(n0);
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}