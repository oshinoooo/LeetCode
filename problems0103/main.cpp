#include <iostream>
#include <vector>
#include <deque>

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
    vector<vector<int>> zigzagLevelOrder1(TreeNode* root) {
        vector<vector<int>> out;
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool direction = true;

        while (!dq.empty()) {
            int length = dq.size();
            vector<int> tmp;
            if (direction) {
                for (int i = 0; i < length; ++i) {
                    auto node = dq.front();
                    dq.pop_front();

                    if (node) {
                        tmp.push_back(node->val);
                        dq.push_back(node->left);
                        dq.push_back(node->right);
                    }
                }
            }
            else {
                for (int i = 0; i < length; ++i) {
                    auto node = dq.back();
                    dq.pop_back();

                    if (node) {
                        tmp.push_back(node->val);
                        dq.push_front(node->right);
                        dq.push_front(node->left);
                    }
                }
            }

            if (!tmp.empty())
                out.push_back(tmp);

            direction = !direction;
        }

        return out;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> out;
        deque<TreeNode*> dq;
        dq.push_back(root);
        int level = 1;

        while (!dq.empty()) {
            int n = dq.size();
            vector<int> tmp;

            if (level % 2 == 1) {
                for (int i = 0; i < n; ++i) {
                    TreeNode* node = dq.front();
                    dq.pop_front();

                    if (!node)
                        continue;

                    tmp.push_back(node->val);
                    dq.push_back(node->left);
                    dq.push_back(node->right);
                }
            }
            else {
                for (int i = 0; i < n; ++i) {
                    TreeNode* node = dq.back();
                    dq.pop_back();

                    if (!node)
                        continue;

                    tmp.push_back(node->val);
                    dq.push_front(node->right);
                    dq.push_front(node->left);
                }
            }

            ++level;

            if (!tmp.empty())
                out.push_back(tmp);
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
    vector<vector<int>> out = s.zigzagLevelOrder(n1);
    for (auto ou : out) {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}
