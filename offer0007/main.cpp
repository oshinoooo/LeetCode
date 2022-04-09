#include <iostream>
#include <vector>
#include <unordered_map>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        for (int i = 0; i < n; ++i)
            indexes[inorder[i]] = i;

        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }

private:
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preHead, int preTail, int inoHead, int inoTail) {
        if (preTail < preHead || inoTail < inoHead)
            return nullptr;

        int value = preorder[preHead];

        TreeNode* root = new TreeNode(value);

        int leftLength = indexes[value] - inoHead;

        int leftHead1 = preHead + 1;
        int leftTail1 = preHead + leftLength;
        int leftHead2 = inoHead;
        int leftTail2 = indexes[value] - 1;

        int rightHead1 = preHead + leftLength + 1;
        int rightTail1 = preTail;
        int rightHead2 = indexes[value] + 1;
        int rightTail2 = inoTail;

        root->left = myBuildTree(preorder, inorder, leftHead1, leftTail1, leftHead2, leftTail2);
        root->right = myBuildTree(preorder, inorder, rightHead1, rightTail1, rightHead2, rightTail2);

        return root;
    }

private:
    unordered_map<int, int> indexes;
};

int main() {
    cout << "--------------------" << endl;
    Solution s;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = s.buildTree(preorder, inorder);
    showTree(root);
    cout << endl;
    cout << "--------------------" << endl;
    return 0;
}