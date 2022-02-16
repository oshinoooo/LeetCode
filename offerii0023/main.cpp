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
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;

        while (curA != curB) {
            if (!curA)
                curA = headB;
            else
                curA = curA->next;

            if (!curB)
                curB = headA;
            else
                curB = curB->next;
        }

        return curA;
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
    ListNode* n6 = new ListNode(6);
    ListNode* n7 = new ListNode(7);
    ListNode* n8 = new ListNode(8);

    ListNode* n9 = new ListNode(9);
    ListNode* n10 = new ListNode(10);
    ListNode* n11 = new ListNode(11);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n9;

    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;

    n9->next = n10;
    n10->next = n11;

    ListNode* n0 = s.getIntersectionNode(n1, n5);
    while (n0 != nullptr) {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
