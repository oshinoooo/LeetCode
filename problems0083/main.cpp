#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* curr = head->next;

        ListNode* newHead = new ListNode(0, head);
        ListNode* tail = head;
        tail->next = nullptr;

        while (curr) {
            if (tail->val != curr->val) {
                tail->next = curr;
                curr = curr->next;
                tail = tail->next;
                tail->next = nullptr;
            }
            else
                curr = curr->next;
        }

        return newHead->next;
    }
};

int main()
{
    cout << "------------------" << endl;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(2);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    Solution s;
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