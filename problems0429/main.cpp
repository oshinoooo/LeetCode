#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
public:
    int val;
    vector<Node*> children;

    Node(int _val) : val(_val) {}
    Node(int _val, vector<Node*> _children) : val(_val), children(_children) {}
};

class Solution {
public:
    // DFS
    vector<vector<int>> levelOrder(Node* root) {
        if (!root)
            return {};
        vector<vector<int>> out;
        dfs(root, 0, out);
        return out;
    }

    void dfs(Node* root, int curHeight, vector<vector<int>>& out) {
        if (!root)
            return;

        while (out.size() < curHeight + 1)
            out.push_back({});

        out[curHeight].push_back(root->val);
        for (const auto& node : root->children)
            dfs(node, curHeight + 1, out);
    }

    // BFS
    vector<vector<int>> levelOrder2(Node* root) {
        if (!root)
            return {};

        vector<vector<int>> out;

        queue<Node*> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            vector<int> tmp;

            for (int i = 0; i < size; ++i) {
                Node* node = que.front();
                que.pop();
                tmp.push_back(node->val);

                for (int j = 0; j < node->children.size(); ++j)
                    que.push(node->children[j]);
            }

            out.push_back(tmp);
        }

        return out;
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

    n1->children.push_back(n3);
    n1->children.push_back(n2);
    n1->children.push_back(n4);
    n3->children.push_back(n5);
    n3->children.push_back(n6);

    Solution s;
    vector<vector<int>> outs = s.levelOrder(n1);
    for (auto out : outs) {
        for (auto num : out)
            cout << num << " ";
        cout << endl;
    }
    cout << "--------------------" << endl;
    return 0;
}