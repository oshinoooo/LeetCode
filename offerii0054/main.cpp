#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cctype>
#include <numeric>
#include <math.h>

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
    TreeNode* convertBST(TreeNode* root) {
        count(root, 0);
        return root;
    }

private:
    int count(TreeNode* root, int parentSum) {
        if (!root)
            return 0;

        int value = root->val;

        int rightSum = count(root->right, parentSum);
        int leftSum = count(root->left, rightSum + value + parentSum);

        root->val = parentSum + rightSum + value;

        return leftSum + rightSum + value;
    }
};

int main() {
    cout << "---------------------" << endl;
    TreeNode* n1 = new TreeNode(4);
    TreeNode* n2 = new TreeNode(1);
    TreeNode* n3 = new TreeNode(6);
    TreeNode* n4 = new TreeNode(0);
    TreeNode* n5 = new TreeNode(2);
    TreeNode* n6 = new TreeNode(5);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n8 = new TreeNode(3);
    TreeNode* n9 = new TreeNode(8);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    n5->right = n8;
    n7->right = n9;

    showTree(n1);
    cout << endl;

    Solution s;
    TreeNode* n0 = s.convertBST(n1);

    showTree(n0);
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
