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
//    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//        return my_buildTree(preorder, inorder);
//    }
//
//private:
//    TreeNode* my_buildTree(vector<int>& preorder, vector<int>& inorder) {
//        if (preorder.empty()) {
//            return nullptr;
//        }
//
//        TreeNode* root = new TreeNode(preorder[0]);
//
//        vector<int> left_preorder;
//        vector<int> left_inorder;
//        vector<int> right_preorder;
//        vector<int> right_inorder;
//
//        for (int i = 0; i < inorder.size(); ++i) {
//            if (inorder[i] == preorder[0]) {
//                left_preorder.insert(left_preorder.begin(), preorder.begin() + 1, preorder.begin() + 1 + i);
//                left_inorder.insert(left_inorder.begin(), inorder.begin(), inorder.begin() + i);
//                right_preorder.insert(right_preorder.begin(), preorder.begin() + 1 + i, preorder.end());
//                right_inorder.insert(right_inorder.begin(), inorder.begin() + i + 1, inorder.end());
//            }
//        }
//
//        root->left = my_buildTree(left_preorder, left_inorder);
//        root->right = my_buildTree(right_preorder, right_inorder);
//
//        return root;
//    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_index;
        for(int i = 0; i < inorder.size(); i++)
            inorder_index[inorder[i]] = i;
        return recur(preorder, inorder_index, 0, 0, inorder.size() - 1);
    }

private:
    TreeNode* recur(vector<int>& preorder, unordered_map<int, int>& inorder_index, int root, int left, int right) {
        if(right < left)
            return nullptr;

        TreeNode* node = new TreeNode(preorder[root]);
        int mid = inorder_index[preorder[root]];
        node->left = recur(preorder, inorder_index, root + 1, left, mid - 1);
        node->right = recur(preorder, inorder_index, root + mid - left + 1, mid + 1, right);
        return node;
    }
};

void DLR(TreeNode* root) {
    if (root == nullptr)
        return;
    cout << root->val << " ";
    DLR(root->left);
    DLR(root->right);
}

int main() {
    cout << "---------------------" << endl;
    Solution s;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = s.buildTree(preorder, inorder);
    DLR(root);
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
