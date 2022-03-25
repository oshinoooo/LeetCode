#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int _val) : val(_val), next(nullptr) {}
    ListNode(int _val, ListNode* _next) : val(_val), next(_next) {}
};

class Solution {
public:
    ListNode* detectCycle1(ListNode* head) {
        if (!head || !head->next)
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (slow != fast) {
            slow = slow->next;
            if (!fast || !fast->next)
                return nullptr;
            fast = fast->next->next;
        }

        slow = slow->next;
        ListNode* curr = head;

        while (slow != curr) {
            slow = slow->next;
            curr = curr->next;
        }

        return slow;
    }

    ListNode* detectCycle(ListNode* head) {
        if (!head || !head->next)
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (slow != fast) {
            slow = slow->next;
            if (fast && fast->next)
                fast = fast->next->next;
            else
                return nullptr;
        }

        slow = slow->next;
        ListNode* curr = head;
        while (slow != curr) {
            slow = slow->next;
            curr = curr->next;
        }

        return slow;
    }
};

int main() {
    cout << "---------------------" << endl;
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
    n5->next = n3;

    ListNode* n0 = s.detectCycle(n1);
    if (n0) cout << n0->val << endl;
    cout << "---------------------" << endl;
    return 0;
}