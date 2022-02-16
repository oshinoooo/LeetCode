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

void DLR(TreeNode* root) {
    if (root == nullptr)
        return;
    cout << root->val << " ";
    DLR(root->left);
    DLR(root->right);
}

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        return myIncreasingBST(root, nullptr);
    }

    TreeNode* myIncreasingBST(TreeNode* root, TreeNode* nextRight) {
        if (root) {
            TreeNode* curRight = myIncreasingBST(root->right, nextRight);
            nextRight = myIncreasingBST(root->left, root);
            root->left = nullptr;
            root->right = curRight;
        }
        return nextRight;
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
    TreeNode* n0 = s.increasingBST(n1);
    DLR(n0);
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
