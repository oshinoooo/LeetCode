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

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root)
            return false;

        bool out = false;
        out |= check(root, subRoot);
        out |= isSubtree(root->left, subRoot);
        out |= isSubtree(root->right, subRoot);

        return out;
    }

private:
    bool check(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot)
            return true;

        if ((root && !subRoot) || (!root && subRoot) || (root->val != subRoot->val))
            return false;

        return check(root->left, subRoot->left) && check(root->right, subRoot->right);
    }
};

int main() {
    cout << "--------------------" << endl;
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

    TreeNode* n0 = new TreeNode(2);
    TreeNode* n8 = new TreeNode(1);
    TreeNode* n9 = new TreeNode(3);

    n0->left = n8;
    n0->right = n9;

    Solution s;

    string out = s.isSubtree(n1, n0) == true ? "true" : "false";
    cout << out << endl;
    cout << "--------------------" << endl;
    return 0;
}