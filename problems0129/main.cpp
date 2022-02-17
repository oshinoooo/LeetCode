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
    int sumNumbers1(TreeNode* root) {
        if (!root)
            return 0;

        stack<pair<TreeNode*, int>> stk;
        stk.push({root, 0});

        int sum = 0;
        while (!stk.empty()) {
            auto [node, tmp] = stk.top();
            stk.pop();

            if (!node->left && !node->right)
                sum += tmp * 10 + node->val;
            else {
                if (node->left)
                    stk.push({node->left, tmp * 10 + node->val});
                if (node->right)
                    stk.push({node->right, tmp * 10 + node->val});
            }
        }

        return sum;
    }

    int sumNumbers2(TreeNode* root) {
        if (!root)
            return 0;

        queue<pair<TreeNode*, int>> que;
        que.push({root, 0});

        int sum = 0;

        while (!que.empty()) {
            auto [node, tmp] = que.front();
            que.pop();

            int nextTmp = tmp * 10 + node->val;

            if (!node->left && !node->right)
                sum += nextTmp;
            else {
                if (node->left)
                    que.push({node->left, nextTmp});
                if (node->right)
                    que.push({node->right, nextTmp});
            }
        }

        return sum;
    }

    int sumNumbers(TreeNode* root) {
        return mySumNumbers(root, 0);
    }

private:
    int mySumNumbers(TreeNode* root, int sum) {
        if (!root)
            return 0;
        int tmp = sum * 10 + root->val;
        if (!root->left && !root->right)
            return tmp;
        return mySumNumbers(root->left, tmp) + mySumNumbers(root->right,tmp);
    }
};

int main() {
    cout << "---------------------" << endl;
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(1);
    TreeNode* n5 = new TreeNode(3);
    TreeNode* n6 = new TreeNode(5);
    TreeNode* n7 = new TreeNode(7);

    n1->left = n2;
    n1->right = n3;
//    n2->left = n4;
//    n2->right = n5;
//    n3->left = n6;
//    n3->right = n7;

    Solution s;
    cout << s.sumNumbers(n1) << endl;
    cout << "---------------------" << endl;
    return 0;
}
