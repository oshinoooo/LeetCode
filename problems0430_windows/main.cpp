#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <cctype>
#include <numeric>
#include <math.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node
{
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node (int value) : val(value), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution
{
public:
    Node* flatten(Node* head)
    {
        if (head == nullptr)
            return nullptr;

        stack<Node*> tmp;
        tmp.push(head);
        Node* new_head = new Node(0);
        Node* pre = new_head;
        Node* cur;

        while (!tmp.empty())
        {
            if (tmp.top() == nullptr)
            {
                tmp.pop();
                continue;
            }

            cur = tmp.top();
            tmp.pop();

            tmp.push(cur->next);
            tmp.push(cur->child);

            pre->next = cur;
            cur->prev = pre;
            cur->child = nullptr;
            pre = cur;
        }

        new_head->next->prev = nullptr;
        return new_head->next;
    }
};

int main_backup()
{
    // list
    cout << "--------------------" << endl;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // tree
    cout << "--------------------" << endl;
//    TreeNode* n1 = new TreeNode(1);
//    TreeNode* n2 = new TreeNode(2);
//    TreeNode* n3 = new TreeNode(3);
//    TreeNode* n4 = new TreeNode(4);
//    TreeNode* n5 = new TreeNode(5);
//    TreeNode* n6 = new TreeNode(6);
//    TreeNode* n7 = new TreeNode(7);
//
//    n1->left = n2;
//    n1->right = n3;
//    n2->left = n4;
//    n2->right = n5;
//    n3->left = n6;
//    n3->right = n7;

    // show
    cout << "--------------------" << endl;
//    vector<int> out;
//    for (auto num : out)
//        cout << num << " ";
//    cout << endl;

    vector<vector<int>> out;
    for (auto ou : out)
    {
        for (auto o : ou)
            cout << o << " ";
        cout << endl;
    }

    cout << "--------------------" << endl;
    return 0;
}

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
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    Node* n10 = new Node(10);
    Node* n11 = new Node(11);
    Node* n12 = new Node(12);

    n1->next = n2;
    n1->prev = nullptr;
    n1->child = nullptr;

    n2->next = n3;
    n2->prev = n1;
    n2->child = nullptr;

    n3->next = n4;
    n3->prev = n2;
    n3->child = n7;

    n4->next = n5;
    n4->prev = n3;
    n4->child = nullptr;

    n5->next = n6;
    n5->prev = n4;
    n5->child = nullptr;

    n6->next = nullptr;
    n6->prev = n5;
    n6->child = nullptr;

    n7->next = n8;
    n7->prev = nullptr;
    n7->child = nullptr;

    n8->next = n9;
    n8->prev = n7;
    n8->child = n11;

    n9->next = n10;
    n9->prev = n8;
    n9->child = nullptr;

    n10->next = nullptr;
    n10->prev = n9;
    n10->child = nullptr;

    n11->next = n12;
    n11->prev = nullptr;
    n11->child = nullptr;

    n12->next = nullptr;
    n12->prev = n11;
    n12->child = nullptr;

    Node* n0 = s.flatten(n1);
    n0 = n0->next;
    while (n0->next != nullptr)
    {
        cout << "val     : " << n0->val << endl;
        cout << "next val: " << n0->next->val << endl;
        cout << "prev val: " << n0->prev->val << endl;
        n0 = n0->next;
    }
    cout << "---------------------" << endl;
    return 0;
}
