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

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (myPruneTree(root))
            return root;
        return nullptr;
    }

private:
    int myPruneTree(TreeNode* root) {
        if (!root)
            return 0;

        int valueLeft = myPruneTree(root->left);
        if (valueLeft == 0)
            root->left = nullptr;

        int valueRight = myPruneTree(root->right);
        if (valueRight == 0)
            root->right = nullptr;

        return valueLeft + valueRight + root->val;
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

    Solution s;
    TreeNode* n0 = s.pruneTree(n1);
    cout << "---------------------" << endl;
    return 0;
}
