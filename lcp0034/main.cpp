#include <iostream>
#include <unordered_map>

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
    int maxValue(TreeNode* root, int k) {
        if(!root)
            return 0;

        maxValue(root->left, k);
        maxValue(root->right, k);

        // 1、左右子树都染色
        for(auto& [lcnt, lv]: colored[root->left]) {
            for(auto& [rcnt, rv]: colored[root->right]) {
                // 当前节点不染色
                uncolored[root] = max(uncolored[root], lv+rv);
                if(lcnt + rcnt + 1 > k) continue;
                // 当前节点染色
                colored[root][lcnt+rcnt+1] = max(colored[root][lcnt+rcnt+1], lv+rv+root->val);
            }
        }

        // 2、左子树不染色，右子树染色
        for(auto& [rcnt, rv]: colored[root->right]) {
            // 当前节点不染色
            uncolored[root] = max(uncolored[root], uncolored[root->left]+rv);
            if(rcnt + 1 > k) continue;
            // 当前节点染色
            colored[root][rcnt+1] = max(colored[root][rcnt+1], uncolored[root->left]+rv+root->val);
        }

        // 3、左子树染色，右子树不染色
        for(auto& [lcnt, lv]: colored[root->left]) {
            // 当前节点不染色
            uncolored[root] = max(uncolored[root], uncolored[root->right]+lv);
            if(lcnt + 1 > k) continue;
            // 当前节点染色
            colored[root][lcnt+1] = max(colored[root][lcnt+1], uncolored[root->right]+lv+root->val);
        }
        // 4、左右子树都不染色
        // 当前节点不染色
        uncolored[root] = max(uncolored[root], uncolored[root->left]+uncolored[root->right]);
        // 当前节点染色
        colored[root][1] = max(colored[root][1], uncolored[root->left]+uncolored[root->right]+root->val);

        int res = uncolored[root];
        for(auto& [cnt, v]: colored[root])
            res = max(res, v);
        return res;
    }

private:
    unordered_map<TreeNode*, int> uncolored; // 当前子树根节点不染色能获得的最大价值和
    unordered_map<TreeNode*, unordered_map<int, int>> colored; // 染色的话要额外记录左右子树根节点连续染色的节点数
};

int main() {
    cout << "--------------------" << endl;
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n9 = new TreeNode(9);
    TreeNode* n2 = new TreeNode(2);

    n4->left = n1;
    n4->right = n3;
    n1->left = n9;
    n3->right = n2;

    Solution s;
    cout << s.maxValue(n4, 2) << endl;
    cout << "--------------------" << endl;
    return 0;
}