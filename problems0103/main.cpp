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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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
