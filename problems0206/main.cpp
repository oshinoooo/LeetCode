#include <iostream>
#include <vector>

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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};

int main() {
    cout << "--------------------" << endl;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);
    ListNode* n7 = new ListNode(7);
    ListNode* n8 = new ListNode(8);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;

    Solution s;

    ListNode* n0 = s.reverseList(n1);
    while (n0) {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;
    cout << "--------------------" << endl;
    return 0;
}
