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

void showTree(TreeNode* root) {
    if (root == nullptr) return;
    showTree(root->left);
    cout << root->val << " ";
    showTree(root->right);
}

/*
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        ptr = 0;
        LDR(root);
    }

    int next() {
        return nums[ptr++];
    }

    bool hasNext() {
        return ptr < nums.size();
    }

private:
    void LDR(TreeNode* root) {
        if (!root) return;
        LDR(root->left);
        nums.push_back(root->val);
        LDR(root->right);
    }

private:
    vector<int> nums;
    int ptr;
};
*/

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
    }

    int next() {
        TreeNode* node = stk.top();
        stk.pop();

        if (!node)
            next();

        int out = node->val;

        node = node->right;
        while (node) {
            stk.push(node);
            node = node->left;
        }

        return out;
    }

    bool hasNext() {
        while (!stk.empty() && stk.top() == nullptr)
            stk.pop();
        return !stk.empty();
    }

private:
    stack<TreeNode*> stk;
};

int main() {
    cout << "---------------------" << endl;
    TreeNode* n1 = new TreeNode(7);
    TreeNode* n2 = new TreeNode(3);
    TreeNode* n3 = new TreeNode(15);
    TreeNode* n4 = new TreeNode(1);
    TreeNode* n5 = new TreeNode(3);
    TreeNode* n6 = new TreeNode(9);
    TreeNode* n7 = new TreeNode(20);

    n1->left = n2;
    n1->right = n3;
//    n2->left = n4;
//    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    BSTIterator bstIterator(n1);
    string str;

    cout << bstIterator.next() << endl;

    cout << bstIterator.next() << endl;
    str = bstIterator.hasNext() ? "true" : "false";
    cout << str << endl;

    cout << bstIterator.next() << endl;
    str = bstIterator.hasNext() ? "true" : "false";
    cout << str << endl;

    cout << bstIterator.next() << endl;
    str = bstIterator.hasNext() ? "true" : "false";
    cout << str << endl;

    cout << bstIterator.next() << endl;
    str = bstIterator.hasNext() ? "true" : "false";
    cout << str << endl;
    cout << "---------------------" << endl;
    return 0;
}
