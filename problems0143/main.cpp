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
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;
        merge(head, reverse(findMid(head)));
    }

private:
    ListNode* findMid(ListNode* head) {
        ListNode* prev;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
        }

        prev->next = nullptr;
        return slow;
    }

    ListNode* reverse(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    ListNode* merge(ListNode* head1,ListNode* head2) {
        ListNode* newHead = new ListNode();
        ListNode* curr = newHead;
        ListNode* ptr1 = head1;
        ListNode* ptr2 = head2;

        while (ptr1 && ptr2) {
            curr->next = ptr1;
            ptr1 = ptr1->next;
            curr = curr->next;

            curr->next = ptr2;
            ptr2 = ptr2->next;
            curr = curr->next;
        }

        if (ptr2) {
            curr->next = ptr2;
            ptr2 = ptr2->next;
            curr = curr->next;
        }

        return newHead->next;
    }
};

int main() {
    cout << "---------------------" << endl;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);
    ListNode* n7 = new ListNode(7);
    ListNode* n8 = new ListNode(8);
    ListNode* n9 = new ListNode(9);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;

    Solution s;
    s.reorderList(n1);

    ListNode* n0 = n1;
    while (n0 != nullptr) {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}