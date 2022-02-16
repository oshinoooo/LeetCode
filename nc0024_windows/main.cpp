#include <iostream>
#include <map>

using namespace std;

struct ListNode
{
    ListNode(int value) : val(value) {}
    int val;
    struct ListNode *next;
};

class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        map<int, bool> count;
        ListNode* tmp = head;
        while (tmp != nullptr)
        {
            if (!count.count(tmp->val))
                count.insert(make_pair(tmp->val, false));
            else
                count[tmp->val] = true;
            tmp = tmp->next;
        }

        ListNode* new_head = new ListNode(0);
        new_head->next = head;

        ListNode* pre = new_head;

        while (head != nullptr)
        {
            if (count[head->val])
                pre->next = head->next;
            else
                pre = pre->next;
            head = head->next;
        }

        return new_head->next;
    }
};

int main()
{
    cout << "-----------------------" << endl;
    Solution s;
    ListNode* l1 = new ListNode(1);
    cout << l1->val << endl;
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(2);

    l1->next = l2;
    l2->next = l3;

    ListNode* out = l1;
//    out = s.deleteDuplicates(l1);

    while (out != nullptr)
    {
        cout << out->val << endl;
        out = out->next;
    }
    cout << "-----------------------" << endl;
    return 0;
}
