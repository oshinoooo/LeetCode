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
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int _val) : val(_val), next(nullptr) {}
    ListNode(int _val, ListNode* _next) : val(_val), next(_next) {}
};

class Solution {
/*
public:
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* newHead = new ListNode();
        ListNode* cur = newHead;

        while (head1 || head2) {
            if ((head1 && head2 && head1->val < head2->val) || (head1 && !head2)) {
                cur->next = head1;
                head1 = head1->next;
            }
            else {
                cur->next = head2;
                head2 = head2->next;
            }
            cur = cur->next;
        }

        return newHead->next;
    }

    ListNode* sortList(ListNode* head, ListNode* tail) {
        if (!head)
            return head;

        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail)
                fast = fast->next;
        }

        ListNode* mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));
    }
*/

public:
    ListNode* sortList(ListNode* head) {

    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;

    ListNode* n1 = new ListNode(4);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(1);
    ListNode* n4 = new ListNode(3);
    ListNode* n5 = new ListNode(0);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    ListNode* n0 = s.sortList(n1);
    while (n0 != nullptr) {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
