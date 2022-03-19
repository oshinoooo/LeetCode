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
    string tree2str(TreeNode* root) {
        if (!root)
            return "";

        string out;
        myTree2str(root, out);
        out.pop_back();
        return out;
    }

private:
    void myTree2str(TreeNode* root, string& out) {
        if (!out.empty())
            out += "(";

        out += to_string(root->val);

        if (root->left || root->right) {
            if (root->left)
                myTree2str(root->left, out);
            else
                out += "()";

            if (root->right)
                myTree2str(root->right, out);
        }

        out += ")";
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

    Solution s;
    cout << s.tree2str(n1) << endl;
    cout << "--------------------" << endl;
    return 0;
}
