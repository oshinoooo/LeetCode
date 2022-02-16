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

class Node
{
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node*> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    int maxDepth(Node* root)
    {
        if (!root)
            return 0;

        if (root->children.empty())
            return 1;

        int out = 0;
        for (auto& cur : root->children)
            out = max(out, maxDepth(cur));
        return out + 1;
    }
};

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);

    n1->children = {n3, n2, n4};
    n3->children = {n5, n6};

    cout << s.maxDepth(n1) << endl;
    cout << "---------------------" << endl;
    return 0;
}
