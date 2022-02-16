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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int length = inorder.size();
        for (int i = 0; i < length; ++i)
            index[inorder[i]] = i;
        return myBuildTree(inorder, 0, length - 1,
                           postorder, 0, length - 1);
    }

private:
    TreeNode* myBuildTree(const vector<int>& inorder, int inoHead, int inoTail,
                          const vector<int>& postorder, int posHead, int posTail) {
        if (inoTail < inoHead || posTail < posHead)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[posTail]);

        int tmp1= postorder[posTail];

        int leftInoHead = inoHead;
        int leftInoTail = index[postorder[posTail]] - 1;
        int rightInoHead = index[postorder[posTail]] + 1;
        int rightInoTail = inoTail;

        int leftPosHead = posHead;
        int leftPosTail = posHead + leftInoTail - leftInoHead;
        int rightPosHead = leftPosTail + 1;
        int rightPosTail = posTail - 1;

        root->left = myBuildTree(inorder, leftInoHead, leftInoTail,
                                 postorder, leftPosHead, leftPosTail);
        root->right = myBuildTree(inorder, rightInoHead, rightInoTail,
                                  postorder, rightPosHead, rightPosTail);
        return root;
    }

private:
    unordered_map<int, int> index;
};

int main() {
    cout << "---------------------" << endl;
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};

    Solution s;
    showTree(s.buildTree(inorder, postorder));
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
