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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* newHead = new ListNode(0, head);
        ListNode* curr = newHead;

        ListNode* prev = nullptr;
        ListNode* hea2 = nullptr;
        ListNode* tail = nullptr;
        ListNode* next = nullptr;

        int count = 0;
        while (curr) {
            if (count == left - 1)
                prev = curr;

            if (count == left)
                hea2 = curr;

            if (count == right)
                tail = curr;

            if (count == right + 1)
                next = curr;

            curr = curr->next;
            ++count;
        }

        tail->next = nullptr;

        prev->next = reverse(hea2);
        hea2->next = next;

        ListNode* out = newHead->next;
        delete newHead;
        return out;
    }

private:
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
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

    ListNode* n0 = s.reverseBetween(n1, 2, 4);
    while (n0 != nullptr) {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
