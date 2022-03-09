#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() : val(0) {}
    Node(int _value) : val(_value) {}
    Node(int _value, vector<Node*> _children) : val(_value), children(_children) {}
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root)
            return {};
        vector<int> out;
        myPreorder(root, out);
        return out;
    }

private:
    void myPreorder(Node* root, vector<int>& out) {
        out.push_back(root->val);
        for (int i = 0; i < root->children.size(); ++i)
            myPreorder(root->children[i], out);
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
    vector<int> out = s.preorder(n1);
    for (auto num : out)
        cout << num << " ";
    cout << endl;
    cout << "--------------------" << endl;
    return 0;
}
