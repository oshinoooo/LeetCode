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

class Codec {
public:
    string serialize(TreeNode* root) {
        string out;
        mySerialize(root, out);
        return out;
    }

    TreeNode* deserialize(string data) {
        int ptr = 0;
        return myDeserialize(data, ptr);
    }

private:
    void mySerialize(TreeNode* root, string& sequence) {
        if (!root)
            sequence += "*,";
        else {
            sequence += to_string(root->val) + ",";
            mySerialize(root->left, sequence);
            mySerialize(root->right, sequence);
        }
    }

    TreeNode* myDeserialize(string& data, int& ptr) {
        if (data.size() <= ptr || data[ptr] == '*') {
            ptr += 2;
            return nullptr;
        }

        int nextPtr = ptr;
        while (data[nextPtr++] != ',') {}
        string tmp = data.substr(ptr, nextPtr - ptr - 1);
        ptr = nextPtr;

        int num = 0;
        if (tmp[0] == '-')
            num -= stoi(tmp.substr(1, tmp.size() - 1));
        else
            num += stoi(tmp);

        TreeNode* root = new TreeNode(num);
        root->left = myDeserialize(data, ptr);
        root->right = myDeserialize(data, ptr);
        return root;
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

    Codec codec;
    string str = codec.serialize(n1);
    cout << str << endl;

    auto node = codec.deserialize(str);
    DLR(node);
    cout << endl;

    cout << "---------------------" << endl;
    return 0;
}
