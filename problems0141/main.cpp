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
    bool hasCycle1(ListNode *head) {
        if (!head || !head->next)
            return false;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (slow != fast) {
            if (!fast || !fast->next)
                return false;

            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }

    bool hasCycle(ListNode *head) {
        if (!head || !head->next)
            return false;

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != fast) {
            if (!fast || !fast->next)
                return false;

            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
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
    n5->next = n3;

    Solution s;
    cout << s.hasCycle(n1) << endl;
    cout << "---------------------" << endl;
    return 0;
}
