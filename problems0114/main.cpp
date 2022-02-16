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
    void flatten1(TreeNode* root) {
        if (!root)
            return;

        vector<TreeNode*> nodes;
        DlR(root, nodes);

        for (int i = 0; i < nodes.size() - 1; ++i) {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i + 1];
        }

        nodes.back()->left = nullptr;
        nodes.back()->right = nullptr;
    }

    void flatten(TreeNode* root) {
        if (!root)
            return;

        myFlatten(root);
    }

private:
    void DlR(TreeNode* root, vector<TreeNode*>& nodes) {
        if (!root)
            return;

        nodes.push_back(root);
        DlR(root->left, nodes);
        DlR(root->right, nodes);
    }

    TreeNode* myFlatten(TreeNode* root) {
        if (!root)
            return nullptr;

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        root->right = myFlatten(left);
        root->left = nullptr;

        TreeNode* tmp = root;
        while (tmp->right)
            tmp = tmp->right;

        tmp->right = myFlatten(right);

        return root;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;

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

    s.flatten(n1);

    cout << "---------------------" << endl;
    return 0;
}
