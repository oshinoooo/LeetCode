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
        ListNode* outHead = new ListNode(0, head);
        ListNode* curr = outHead;

        ListNode* rHead;
        ListNode* prev;
        ListNode* next;
        for (int i = 0; i <= right; ++i) {
            if (i == left - 1)
                prev = curr;

            if (i == left)
                rHead = curr;

            if (i == right) {
                next = curr->next;
                curr->next = nullptr;
            }

            curr = curr->next;
        }

        prev->next = myReverse(rHead, next);

        return outHead->next;
    }

private:
    ListNode* myReverse(ListNode* head, ListNode* next) {
        auto newHead = new ListNode(0, next);

        while (head) {
            auto tmp = newHead->next;
            newHead->next = head;
            head = head->next;
            newHead->next->next = tmp;
        }

        return newHead->next;
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

//    n1->next = n2;
//    n2->next = n3;
//    n3->next = n4;
//    n4->next = n5;

    ListNode* n0 = s.reverseBetween(n1, 1, 1);
    while (n0 != nullptr) {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
