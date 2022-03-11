#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}
    Node(int _val) : val(_val) {}
    Node(int _val, vector<Node*> _children) : val(_val), children(_children) {}
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> out;
        myPostorder(root, out);
        return out;
    }

private:
    void myPostorder(Node* root, vector<int>& out) {
        if (!root)
            return;

        for (int i = 0; i < root->children.size(); ++i)
            myPostorder(root->children[i], out);

        out.push_back(root->val);
    }
};

int main() {
    cout << "--------------------" << endl;
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);

    n1->children = {n3, n2, n4};
    n3->children = {n5, n6};

    Solution s;
    vector<int> out = s.postorder(n1);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "--------------------" << endl;
    return 0;
}
