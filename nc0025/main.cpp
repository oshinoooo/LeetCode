#include <iostream>
#include <map>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode* next;
    ListNode(int value) : val(value) {}
    ListNode() : val(0), next(nullptr) {}
};

class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* pre = new_head;

        while (head != nullptr)
        {
            if (head->next != nullptr && head->val == head->next->val)
            {
                pre->next = head->next;
                head = head->next;
            }
            else
            {
                pre = pre->next;
                head = head->next;
            }
        }

        return new_head->next;
    }
};

int main()
{
    cout << "-----------------------" << endl;
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(2);
    l1->next = l2;
    l2->next = l3;

    Solution s;
    ListNode* out = s.deleteDuplicates(l1);

    while (out != nullptr)
    {
        cout << out->val << endl;
        out = out->next;
    }
    cout << "-----------------------" << endl;
    return 0;
}
