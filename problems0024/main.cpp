#include <iostream>
#include <vector>

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
    ListNode* swapPairs(ListNode* head)
    {
        if (head == nullptr)
            return nullptr;

        ListNode* cur = head;
        ListNode* c_n = head->next;
        ListNode* new_head = new ListNode(0, head);
        ListNode* pre = new_head;

        while (cur != nullptr && c_n != nullptr)
        {
            pre->next = c_n;
            cur->next = c_n->next;
            c_n->next = cur;

            pre = cur;
            cur = cur->next;
            if (cur == nullptr)
                break;
            c_n = cur->next;
        }

        return new_head->next;
    }
};

int main()
{
    cout << "---------------" << endl;
    Solution s;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    ListNode* n0 = s.swapPairs(n1);
    while (n0 != nullptr)
    {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;
    cout << "---------------" << endl;
    return 0;
}
