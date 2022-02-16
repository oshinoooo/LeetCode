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
    void reorderList1(ListNode* head) {
        vector<ListNode*> nodes;
        while (head) {
            nodes.push_back(head);
            head = head->next;
        }

        int i = 0;
        int ptr1 = 0;
        int ptr2 = nodes.size() - 1;
        ListNode* cur = new ListNode();
        while (ptr1 <= ptr2) {
            if (i++ % 2 == 0)
                cur->next = nodes[ptr1++];
            else
                cur->next = nodes[ptr2--];

            cur = cur->next;
            cur->next = nullptr;
        }
    }

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
        ListNode* newHead = new ListNode();

        while (head) {
            auto tmp = newHead->next;
            newHead->next = head;
            head = head->next;
            newHead->next->next = tmp;
        }

        return newHead->next;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* newHead = new ListNode();

        ListNode* curr = newHead;
        while (head1 || head2) {
            if (head1) {
                curr->next = head1;
                curr = curr->next;
                head1 = head1->next;
            }

            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
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

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;

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
