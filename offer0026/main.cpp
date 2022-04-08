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
    bool isSubStructure1(TreeNode* A, TreeNode* B) {
        if (!A || !B)
            return false;

        return myIsSubStructure(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool myIsSubStructure1(TreeNode*A, TreeNode*B) {
        if (!B)
            return true;

        if (!A || A->val != B->val)
            return false;

        return myIsSubStructure(A->left, B->left) && myIsSubStructure(A->right, B->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B)
            return false;

        return myIsSubStructure(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool myIsSubStructure(TreeNode*A, TreeNode*B) {
        if (!B)
            return true;

        if (!A || A->val != B->val)
            return false;

        return myIsSubStructure(A->left, B->left) && myIsSubStructure(A->right, B->right);
    }
};

int main() {
    cout << "--------------------" << endl;
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

    TreeNode* n8 = new TreeNode(2);
    TreeNode* n9 = new TreeNode(4);
    TreeNode* n10 = new TreeNode(5);

    n8->left = n9;
    n8->right = n10;

    Solution s;
    cout << s.isSubStructure(n1, n8) << endl;
    cout << "--------------------" << endl;
    return 0;
}