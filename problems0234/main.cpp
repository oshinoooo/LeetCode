#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>

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
    bool isPalindrome(ListNode* head) {
        ListNode* head1 = head;
        ListNode* head2 = reverse(findMid(head));

        while (head1 && head2) {
            if (head1->val != head2->val)
                return false;
            head1 = head1->next;
            head2 = head2->next;
        }

        return true;
    }

private:
    ListNode* findMid(ListNode* head) {
        if (!head || !head->next)
            return head;

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
        if (!head || !head->next)
            return head;

        ListNode* newHead = reverse(head->next);
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
    ListNode* n5 = new ListNode(4);
    ListNode* n6 = new ListNode(3);
    ListNode* n7 = new ListNode(2);
    ListNode* n8 = new ListNode(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;

    Solution s;
    cout << s.isPalindrome(n1) << endl;
    cout << "---------------------" << endl;
    return 0;
}
