#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right) : val(_val), left(_left), right(_right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;

        int left = getDepth(root->left);
        int right = getDepth(root->right);

        if (1 < abs(left - right))
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int getDepth(TreeNode* root) {
        if (!root) return 0;
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        return max(left, right) + 1;
    }
};

int main() {
    cout << "--------------------" << endl;
    TreeNode* n1 = new TreeNode(4);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(6);
    TreeNode* n4 = new TreeNode(1);
    TreeNode* n5 = new TreeNode(3);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    Solution s;
    cout << s.isBalanced(n1) << endl;
    cout << "--------------------" << endl;
    return 0;
}