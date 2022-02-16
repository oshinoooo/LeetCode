#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* new_head = new ListNode(0, head);

        ListNode* pre = new_head;
        ListNode* cur = head;

        while (cur != nullptr)
        {
            if (cur->val== val)
                pre->next = cur->next;
            else
                pre = pre->next;

            cur = cur->next;
        }

        return new_head->next;
    }
};

int main()
{
    cout << "-----------------" << endl;
    Solution s;
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(3);
    ListNode* n6 = new ListNode(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    ListNode* n0 = s.removeElements(n1, 3);
    while (n0 != nullptr)
    {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;
    cout << "-----------------" << endl;
    return 0;
}
