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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void DLR(TreeNode* root) {
    if (root == nullptr)
        return;
    cout << root->val << " ";
    DLR(root->left);
    DLR(root->right);
}

class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        m_root = root;
        que.push(m_root);
        while (que.front()->left && que.front()->right) {
            que.push(que.front()->left);
            que.push(que.front()->right);
            que.pop();
        }

        if (que.front()->left)
            que.push(que.front()->left);
    }

    int insert(int v) {
        int fatherValue = que.front()->val;
        TreeNode* node = new TreeNode(v);

        if (!que.front()->left)
            que.front()->left = node;
        else {
            que.front()->right = node;
            que.pop();
        }

        que.push(node);

        return fatherValue;
    }

    TreeNode* get_root() {
        return m_root;
    }

private:
    TreeNode* m_root;
    queue<TreeNode*> que;
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
//    n1->right = n3;
//    n2->left = n4;
//    n2->right = n5;
//    n3->left = n6;
//    n3->right = n7;

    CBTInserter cbtInserter(n1);

    DLR(cbtInserter.get_root());
    cout << endl;

    cout << cbtInserter.insert(3) << endl;
    DLR(cbtInserter.get_root());
    cout << endl;

    cout << cbtInserter.insert(4) << endl;
    DLR(cbtInserter.get_root());
    cout << endl;

    cout << "---------------------" << endl;
    return 0;
}
