#include <iostream>
#include <vector>
#include <stack>

using namespace std;

 struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr) return nullptr;

        stack<ListNode*> staA;
        while (headA != nullptr)
        {
            staA.push(headA);
            headA = headA->next;
        }

        stack<ListNode*> staB;
        while (headB != nullptr)
        {
            staB.push(headB);
            headB = headB->next;
        }

        ListNode* ret = nullptr;
        while (!staA.empty() && !staB.empty())
        {
            if (staA.top() == staB.top())
                ret = staA.top();

            staA.pop();
            staB.pop();
        }

        return ret;
    }
};

int main()
{
    cout << "-----------------------" << endl;
    Solution s;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);

    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);
    ListNode* n7 = new ListNode(7);
    ListNode* n8 = new ListNode(8);

    ListNode* n9 = new ListNode(9);
    ListNode* n10 = new ListNode(10);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n9;

    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;

    n9->next = n10;

    cout << s.getIntersectionNode(n1, n5)->val << endl;
    cout << "-----------------------" << endl;
    return 0;
}
