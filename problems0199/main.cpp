#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right) : val(_val), left(_left), right(_right) {}
};

class Solution {
public:
    vector<int> rightSideView1(TreeNode* root) {
        if (!root)
            return {};

        vector<int> out;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                auto node = que.front();
                que.pop();

                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);

                if (i == size - 1)
                    out.push_back(node->val);
            }
        }

        return out;
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> out;
        queue<TreeNode*> que;
        if (root)
            que.push(root);

        while (!que.empty()) {
            int n = que.size();

            for (int i = 0; i < n; ++i) {
                TreeNode* node = que.front();
                que.pop();

                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);

                if (i == n - 1)
                    out.push_back(node->val);
            }
        }

        return out;
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

    vector<int> out = s.rightSideView(n1);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}