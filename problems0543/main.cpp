#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int out = 0;
        myDiameterOfBinaryTree(root, out);
        return out;
    }

private:
    int myDiameterOfBinaryTree(TreeNode* root, int& out) {
        if (!root)
            return 0;

        int left = myDiameterOfBinaryTree(root->left, out);
        int right = myDiameterOfBinaryTree(root->right, out);

        out = max(out, left + right);

        return max(left, right) + 1;
    }
};

int main() {
    cout << "-------------------------" << endl;
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

    Solution s;
    cout << s.diameterOfBinaryTree(n1) << endl;
    cout << "-------------------------" << endl;
    return 0;
}
