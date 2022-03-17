#include <iostream>
#include <algorithm>

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
    ListNode* getIntersectionNode1(ListNode* headA, ListNode* headB) {
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;

        while (ptr1 != ptr2) {
            if (!ptr1)
                ptr1 = headB;
            else
                ptr1 = ptr1->next;

            if (!ptr2)
                ptr2 = headA;
            else
                ptr2 = ptr2->next;
        }

        return ptr1;
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;

        while (ptr1 != ptr2) {
            if (ptr1)
                ptr1 = ptr1->next;
            else
                ptr1 = headB;

            if (ptr2)
                ptr2 = ptr2->next;
            else
                ptr2 = headA;
        }

        return ptr1;
    }
};

int main() {
    cout << "---------------------" << endl;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    ListNode* n6 = new ListNode(6);
    ListNode* n7 = new ListNode(7);

    n6->next = n7;
    n7->next = n4;

    Solution s;
    cout << s.getIntersectionNode(n1, n6)->val << endl;
    cout << "---------------------" << endl;
    return 0;
}
