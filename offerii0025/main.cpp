#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cctype>
#include <numeric>
#include <math.h>

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
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        vector<int> num1;
        while (l1) {
            num1.push_back(l1->val);
            l1 = l1->next;
        }

        vector<int> num2;
        while (l2) {
            num2.push_back(l2->val);
            l2 = l2->next;
        }

        ListNode* new_head = new ListNode();
        int ptr1 = num1.size() - 1;
        int ptr2 = num2.size() - 1;
        int carry = 0;
        while (0 <= ptr1 || 0 <= ptr2) {
            if (0 <= ptr1 && 0 <= ptr2)
                carry += num1[ptr1--] + num2[ptr2--];
            else if (0 <= ptr1)
                carry += num1[ptr1--];
            else
                carry += num2[ptr2--];

            ListNode* tmp = new ListNode(carry % 10, new_head->next);
            new_head->next = tmp;
            carry /= 10;
        }

        if (carry) {
            ListNode* tmp = new ListNode(1, new_head->next);
            new_head->next = tmp;
        }

        return new_head->next;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* num1 = reverseLinkList(l1);
        ListNode* num2 = reverseLinkList(l2);
        ListNode* head = new ListNode();
        ListNode* curr = head;

        int carry = 0;
        while (num1 || num2) {
            if (num1 && num2) {
                carry += num1->val + num2->val;
                num1 = num1->next;
                num2 = num2->next;
            }
            else if (num1) {
                carry += num1->val;
                num1 = num1->next;
            }
            else {
                carry += num2->val;
                num2 = num2->next;
            }

            curr->next = new ListNode(carry % 10);
            curr = curr->next;
            carry /= 10;
        }

        if (carry) {
            curr->next = new ListNode(1);
        }

        return reverseLinkList(head->next);
    }

private:
    ListNode* reverseLinkList(ListNode* l1) {
        ListNode tmpHead;
        while (l1) {
            ListNode* tmp = tmpHead.next;
            tmpHead.next = l1;
            l1 = l1->next;
            tmpHead.next->next = tmp;
        }
        return tmpHead.next;
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

    ListNode* n6 = new ListNode(6);
    ListNode* n7 = new ListNode(7);
    ListNode* n8 = new ListNode(8);

    n6->next = n7;
    n7->next = n8;

    ListNode* n0 = s.addTwoNumbers(n1, n6);
    while (n0 != nullptr) {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
