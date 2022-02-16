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

void showTree(TreeNode* root) {
    if (root == nullptr) return;
    showTree(root->left);
    cout << root->val << " ";
    showTree(root->right);
}

class Solution {
public:
    // recursive
    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int> out;
        myInorderTraversal(root, out);
        return out;
    }

    // iterate
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        while (root) {
            stk.push(root);
            root = root->left;
        }

        vector<int> out;
        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();

            if (node) {
                out.push_back(node->val);

                node = node->right;
                while (node) {
                    stk.push(node);
                    node = node->left;
                }
            }
        }

        return out;
    }

private:
    void myInorderTraversal(TreeNode* root, vector<int>& out) {
        if (!root)
            return;

        myInorderTraversal(root->left, out);
        out.push_back(root->val);
        myInorderTraversal(root->right, out);
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

    vector<int> out = s.inorderTraversal(n1);
    for (auto num : out)
        cout << num << " ";
    cout << endl;

    cout << "---------------------" << endl;
    return 0;
}
