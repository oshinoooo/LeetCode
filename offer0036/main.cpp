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

typedef TreeNode Node;

class Solution
{
public:
    Node* treeToDoublyList1(Node* root)
    {
        if (!root)
            return nullptr;

        vector<Node*> list;
        LDR(root, list);

        for (int i = 0; i < list.size(); ++i)
        {
            if (i != list.size() - 1)
                list[i]->right = list[i + 1];
            else
                list[i]->right = list[0];

            if (i != 0)
                list[i]->left = list[i - 1];
            else
                list[i]->left = list[list.size() - 1];
        }

        return list[0];
    }

private:
    void LDR(Node* root, vector<Node*>& list)
    {
        if (root == nullptr)
            return;
        LDR(root->left, list);
        list.push_back(root);
        LDR(root->right, list);
    }

public:
    Node* treeToDoublyList(Node* root)
    {
        if(root == nullptr)
            return nullptr;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

private:
    void dfs(Node* cur)
    {
        if(cur == nullptr)
            return;
        dfs(cur->left);

        if(pre != nullptr)
            pre->right = cur;
        else
            head = cur;
        cur->left = pre;
        pre = cur;

        dfs(cur->right);
    }

private:
    Node* pre = nullptr;
    Node* head = nullptr;
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

    ListNode* n0;
    while (n0 != nullptr)
    {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;

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
    vector<int> nums = {};
    vector<int> out;
    for (auto num : out)
        cout << num << " ";
    cout << endl;

//    vector<vector<int>> out;
//    for (auto ou : out)
//    {
//        for (auto o : ou)
//            cout << o << " ";
//        cout << endl;
//    }

    cout << "--------------------" << endl;
    return 0;
}

int main()
{
    cout << "---------------------" << endl;
    Solution s;
    TreeNode* n1 = new TreeNode(4);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(5);
    TreeNode* n4 = new TreeNode(1);
    TreeNode* n5 = new TreeNode(3);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    TreeNode* n0 = s.treeToDoublyList(n1);
    TreeNode* cur = n0;
    do
    {
        cout << cur->val << " ";
        cur = cur->right;
    }
    while (n0 != cur);
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
