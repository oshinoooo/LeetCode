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
    TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder) {
        int length = preorder.size();
        for (int i = 0; i < length; ++i)
            index[inorder[i]] = i;
        return myBuildTree(preorder, 0, length - 1,
                           inorder, 0, length - 1);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    }

private:
    TreeNode* myBuildTree(const vector<int>& preorder, int preHead, int preTail,
                          const vector<int>& inorder, int inoHead, int inoTail) {
        if (preTail < preHead || inoTail < inoHead)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preHead]);

        int leftPreHead = preHead + 1;
        int leftPreTail = preHead + index[preorder[preHead]] - inoHead;
        int rightPreHead = leftPreTail + 1;
        int rightPreTail = preTail;

        int leftInoHead = inoHead;
        int leftInoTail = index[preorder[preHead]] - 1;
        int rightInoHead = index[preorder[preHead]] + 1;
        int rightInoTail = inoTail;

        root->left = myBuildTree(preorder, leftPreHead, leftPreTail,
                                 inorder, leftInoHead, leftInoTail);
        root->right = myBuildTree(preorder, rightPreHead, rightPreTail,
                                  inorder, rightInoHead, rightInoTail);
        return root;
    }

private:
    unordered_map<int, int> index;
};

int main() {
    cout << "---------------------" << endl;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    Solution s;
    showTree(s.buildTree(preorder, inorder));
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
