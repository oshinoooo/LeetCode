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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* new_head = new ListNode(0, head);
        ListNode* lastSorted = head;
        ListNode* curr = head->next;

        while (curr) {
            if (lastSorted->val <= curr->val) {
                lastSorted = lastSorted->next;
            }
            else {
                ListNode* pre = new_head;
                while (pre->next->val <= curr->val)
                    pre = pre->next;

                lastSorted->next = curr->next;
                curr->next = pre->next;
                pre->next = curr;
            }

            curr = lastSorted->next;
        }

        return new_head->next;
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;

    ListNode* n1 = new ListNode(-1);
    ListNode* n2 = new ListNode(5);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(5);
    ListNode* n5 = new ListNode(0);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    ListNode* n0 = s.insertionSortList(n1);
    while (n0 != nullptr) {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
