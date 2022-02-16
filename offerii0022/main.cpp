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
    ListNode *detectCycle1(ListNode *head) {
        unordered_set<ListNode*> s;
        while (!s.count(head) && head) {
            s.insert(head);
            head = head->next;
        }
        return head;
    }

    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast) {
            slow = slow->next;
            if (!fast->next)
                return nullptr;
            fast = fast->next->next;

            if (slow == fast) {
                ListNode* tmp = head;
                while (tmp != slow) {
                    tmp = tmp->next;
                    slow = slow->next;
                }
                return tmp;
            }
        }

        return nullptr;
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
    n5->next = n1;

    ListNode* n0 = s.detectCycle(n1);
    cout << n0->val << endl;
    cout << "---------------------" << endl;
    return 0;
}
