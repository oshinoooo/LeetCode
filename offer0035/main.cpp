#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
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
    Node* next;
    Node* random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution
{
public:
    Node* copyRandomList(Node* head)
    {
        if (head == nullptr)
            return nullptr;

        Node* new_head = new Node(0);
        Node* cur_ori = head;
        Node* cur_new = new_head;

        map<Node*, Node*> m;
        m[nullptr] = nullptr;

        while (cur_ori != nullptr)
        {
            // create new node
            Node* tmp = new Node(cur_ori->val);
            cur_new->next = tmp;
            m[cur_ori] = tmp;

            cur_new = cur_new->next;
            cur_ori = cur_ori->next;
        }

        cur_ori = head;
        cur_new = new_head->next;
        while (cur_ori != nullptr)
        {
            cur_new->random = m[cur_ori->random];
            cur_new = cur_new->next;
            cur_ori = cur_ori->next;
        }

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

    n1->next = n2;
    n1->random = n5;
    n2->next = n3;
    n2->random = n1;
    n3->next = n4;
    n3->random = n2;
    n4->next = n5;
    n4->random = n3;
    n5->next = nullptr;
    n5->random = n4;

    Node* n0 = s.copyRandomList(n1);
    while (n0 != nullptr)
    {
        cout << "n" << n0->val << "->val: " << n0->val << ", ";
        cout << "n" << n0->val << "->random->val: " << n0->random->val << endl;
        n0 = n0->next;
    }
    cout << "---------------------" << endl;
    return 0;
}
