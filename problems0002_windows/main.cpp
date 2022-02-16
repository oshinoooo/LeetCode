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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode();

        int carry = 0;
        ListNode* cur = newHead;
        while (l1 || l2) {
            int value;
            if (l1 && l2) {
                value = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1) {
                value = l1->val + carry;
                l1 = l1->next;
            }
            else {
                value = l2->val + carry;
                l2 = l2->next;
            }

            cur->next = new ListNode(value % 10);
            carry = value / 10;
            cur = cur->next;
        }

        if (carry)
            cur->next = new ListNode(1);

        return newHead->next;
    }
};

int main() {
    cout << "---------------------" << endl;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(0);
    ListNode* n3 = new ListNode(0);
    ListNode* n4 = new ListNode(5);

    ListNode* n5 = new ListNode(2);
    ListNode* n6 = new ListNode(0);
    ListNode* n7 = new ListNode(0);
    ListNode* n8 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    n5->next = n6;
    n6->next = n7;
    n7->next = n8;

    Solution s;
    ListNode* n0 = s.addTwoNumbers(n1, n5);
    while (n0) {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
