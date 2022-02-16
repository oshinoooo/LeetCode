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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev;
        ListNode* subHead;
        ListNode* subTail;
        ListNode* next;

        ListNode* newHead = new ListNode(0, head);
        ListNode* curr = newHead;
        for (int i = 0; i <= right; ++i) {
            if (i == left - 1)
                prev = curr;
            if (i == left)
                subHead = curr;
            if (i == right) {
                subTail = curr;
                next = curr->next;
                subTail->next = nullptr;
                break;
            }
            curr = curr->next;
        }

        prev->next = reverse(subHead);
        subHead->next = next;

        return newHead->next;
    }

private:
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

    ListNode* n0 = s.reverseBetween(n1, 2, 5);
    while (n0) {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
