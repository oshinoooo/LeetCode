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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == nullptr) return nullptr;
        ListNode* pre = head;
        while (pre->next != nullptr)
        {
            if (pre->val == pre->next->val)
                pre->next = pre->next->next;
            else
                pre = pre->next;
        }
        return head;
    }
};

int main()
{
    cout << "------------------" << endl;
    Solution s;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(2);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    ListNode* out = s.deleteDuplicates(n1);
    while (out != nullptr)
    {
        cout << out->val << " ";
        out = out->next;
    }
    cout << endl;
    cout << "------------------" << endl;
    return 0;
}