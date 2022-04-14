#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right) : val(_val), left(_left), right(_right) {}
};

void showTree(TreeNode* root) {
    if (!root) return;
    showTree(root->left);
    cout << root->val << " ";
    showTree(root->right);
}

typedef TreeNode Node;

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr)
            return nullptr;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

private:
    Node *pre, *head;
    void dfs(Node* cur) {
        if(cur == nullptr)
            return;

        dfs(cur->left);

        if(pre != nullptr)
            pre->right = cur;
        else
            head = cur;

        cur->left = pre;
        pre = cur;
        dfs(cur->right);
    }
};

int main() {
    cout << "--------------------" << endl;
    TreeNode* n1 = new TreeNode(4);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(5);
    TreeNode* n4 = new TreeNode(1);
    TreeNode* n5 = new TreeNode(3);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    Solution s;

    TreeNode* n0 = s.treeToDoublyList(n1);
    showTree(n0);
    cout << endl;
    cout << "--------------------" << endl;
    return 0;
}