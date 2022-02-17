#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> tmp;
        vector<vector<int>> out;
        myPathSum(root, targetSum, tmp, out);
        return out;
    }

private:
    void myPathSum(TreeNode* root, int targetSum, vector<int>& tmp, vector<vector<int>>& out) {
        if (!root)
            return;

        tmp.push_back(root->val);
        targetSum -= root->val;

        if (!root->left && !root->right && 0 == targetSum)
            out.push_back(tmp);
        else {
            myPathSum(root->left, targetSum, tmp, out);
            myPathSum(root->right, targetSum, tmp, out);
        }

        tmp.pop_back();
    }
};

int main() {
    cout << "---------------------" << endl;
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(3);
    TreeNode* n5 = new TreeNode(3);
    TreeNode* n6 = new TreeNode(2);
    TreeNode* n7 = new TreeNode(2);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    Solution s;
    vector<vector<int>> out = s.pathSum(n1, 6);
    for (auto ou : out) {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
