#include <iostream>
#include <vector>
#include <queue>

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
    bool hasPathSum1(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        return myHasPathSum(root, targetSum, 0);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        queue<pair<TreeNode*, int>> que;
        que.push({root, 0});

        while (!que.empty()) {
            auto [node, sum] = que.front();
            que.pop();

            if (node) {
                if (!node->left && !node->right) {
                    if (sum + node->val == targetSum)
                        return true;
                }

                que.push({node->left, sum + node->val});
                que.push({node->right, sum + node->val});
            }
        }

        return false;
    }

private:
    bool myHasPathSum(TreeNode* root, const int& targetSum, int currSum) {
        currSum += root->val;

        if (!root->left && !root->right) {
            if (currSum == targetSum)
                return true;
            return false;
        }

        if (root->left) {
            if (myHasPathSum(root->left, targetSum, currSum))
                return true;
        }

        if (root->right)
            return myHasPathSum(root->right, targetSum, currSum);

        return false;
    }
};

int main() {
    cout << "----------------"<< endl;
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
    cout << s.hasPathSum(n1, 11) << endl;
    cout << "----------------"<< endl;
    return 0;
}
