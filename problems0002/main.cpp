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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* head = l1;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr)
        {
            if (l1 == nullptr)
            {
                int tmp = l2->val + carry;
                if (tmp > 9)
                {
                    carry = 1;
                    tmp -= 10;
                }
                l1->next = new ListNode(tmp);
                return head;
            }
            else if (l2 == nullptr)
            {
                l1->val += carry;
                return head;
            }
            else
            {
                int tmp = l1->val + l2->val + carry;
                if (tmp > 9)
                {
                    l1->val = tmp - 10;
                    carry = 1;
                }
                else
                {
                    l1->val = tmp;
                    carry = 0;
                }
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        return head;



        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};

int main()
{
    cout << "------------------" << endl;
    Solution s;
    ListNode* l1 = new ListNode(9);
    ListNode* l2 = new ListNode(9);
    ListNode* l3 = new ListNode(9);
    ListNode* l4 = new ListNode(9);
    ListNode* l5 = new ListNode(9);
    ListNode* l6 = new ListNode(9);
    ListNode* l7 = new ListNode(9);

    ListNode* l8 = new ListNode(9);
    ListNode* l9 = new ListNode(9);
    ListNode* l10 = new ListNode(9);
    ListNode* l11 = new ListNode(9);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;

    l8->next = l9;
    l9->next = l10;
    l10->next = l11;

    ListNode* out = s.addTwoNumbers(l1, l8);

    while (out != nullptr)
    {
        cout << out->val << " ";
        out = out->next;
    }

    cout << endl;
    cout << "------------------" << endl;
    return 0;
}
