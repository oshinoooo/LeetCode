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
    vector<vector<int>> levelOrder1(TreeNode* root) {
        vector<vector<int>> out;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int length = que.size();
            vector<int> tmp;

            for (int i = 0; i < length; ++i) {
                TreeNode* node = que.front();
                que.pop();

                if (node) {
                    tmp.push_back(node->val);
                    que.push(node->left);
                    que.push(node->right);
                }
            }
            if (!tmp.empty())
                out.push_back(tmp);
        }

        return out;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> out;
        myLevelOrder(root, 1, out);
        return out;
    }

private:
    void myLevelOrder(TreeNode* root, int level, vector<vector<int>>& out) {
        if (!root)
            return;

        if (out.size() < level)
            out.resize(level);

        out[level - 1].push_back(root->val);
        myLevelOrder(root->left, level + 1, out);
        myLevelOrder(root->right, level + 1, out);
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
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    Solution s;
    vector<vector<int>> out = s.levelOrder(n1);
    for (auto ou : out) {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
