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
#include <ctime>

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
    bool isBalanced(TreeNode* root) {
        return myIsBalanced(root) != -1;
    }

    bool isBalanced2(TreeNode* root) {

    }

private:
    int myIsBalanced(TreeNode* root) {
        if (!root)
            return 0;

        int leftDepth = myIsBalanced(root->left);
        if (leftDepth == -1)
            return -1;

        int rightDepth = myIsBalanced(root->right);
        if (rightDepth == -1 || 1 < abs(leftDepth - rightDepth))
            return -1;

        return max(leftDepth, rightDepth) + 1;
    }
};

int main() {
    cout << "---------------------" << endl;
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n7 = new TreeNode(7);

    n1->left = n2;
//    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
//    n3->left = n6;
//    n3->right = n7;

    Solution s;
    cout << s.isBalanced(n1) << endl;
    cout << "---------------------" << endl;
    return 0;
}
