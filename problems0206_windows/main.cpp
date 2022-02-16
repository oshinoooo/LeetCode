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
#include <ctime>

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
    ListNode* reverseList1(ListNode* head) {
        ListNode* newHead = new ListNode();
        while (head) {
            auto tmp = newHead->next;
            newHead->next = head;
            head = head->next;
            newHead->next->next = tmp;
        }
        return newHead->next;
    }

    ListNode* reverseList2(ListNode* head) {
        if (!head || !head->next)
            return head;

        // always return the same newHead
        auto newHead = reverseList(head->next);

        // reverse
        head->next->next = head;

        // current tail
        head->next = nullptr;

        return newHead;
    }

    ListNode* reverseList3(ListNode* head) {
        ListNode* newHead = new ListNode();

        while (head) {
            ListNode* tmp = newHead->next;
            newHead->next = head;
            head = head->next;
            newHead->next->next = tmp;
        }

        return newHead->next;
    }

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
    cout << "---------------------" << endl;
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
    cout << "---------------------" << endl;
    return 0;
}
