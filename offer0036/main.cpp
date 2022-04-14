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

typedef TreeNode Node;

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root)
            return nullptr;

        dfs(root);

        head->left = pre;
        pre->right = head;

        return head;
    }

private:
    void dfs(Node* cur) {
        if(!cur)
            return;

        dfs(cur->left);

        if(pre)
            pre->right = cur;
        else
            head = cur;

        cur->left = pre;
        pre = cur;

        dfs(cur->right);
    }

private:
    Node* pre;
    Node* head;
};

int main() {
    cout << "--------------------" << endl;
    Node* n1 = new TreeNode(4);
    Node* n2 = new TreeNode(2);
    Node* n3 = new TreeNode(5);
    Node* n4 = new TreeNode(1);
    Node* n5 = new TreeNode(3);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    Solution s;

    TreeNode* n0 = (TreeNode*)s.treeToDoublyList(n1);
    cout << "--------------------" << endl;
    return 0;
}