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
    ListNode* prev;
    ListNode* next;
    ListNode() : val(0), next(nullptr), prev(nullptr) {}
    ListNode(int _val) : val(_val), next(nullptr), prev(nullptr) {}
    ListNode(int _val, ListNode* _next, ListNode* _prev) : val(_val), next(_next), prev(_prev) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
//        return mergeSort(head);

        ListNode* tail = head;
        while (tail->next)
            tail = tail->next;
        return quickSort(head, tail);
    }

private:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* newHead = new ListNode();
        ListNode* curr = newHead;

        while (head1 && head2) {
            if (head1->val < head2->val) {
                curr->next = head1;
                head1 = head1->next;
            }
            else {
                curr->next = head2;
                head2 = head2->next;
            }

            curr = curr->next;
            curr->next = nullptr;
        }

        if (head1)
            curr->next = head1;
        else if (head2)
            curr->next = head2;

        ListNode* out = newHead->next;
        delete newHead;
        return out;
    }

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

    ListNode* mergeSort(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* head1 = head;
        ListNode* head2 = findMid(head);
        return merge(mergeSort(head1), mergeSort(head2));
    }

    void swapNodes(ListNode* node1, ListNode* node2) {
        ListNode* node1Prev = node1->prev;
        ListNode* node1Next = node1->next;

        ListNode* node2Prev = node2->prev;
        ListNode* node2Next = node2->next;

        if (node1 == node2Prev) {
            node1->next = node2Next;
            node2Next->prev = node1;

            node2->next = node1;
            node1->prev = node2;

            node1Prev->next = node2;
            node2->prev = node1Prev;
        }
        else if (node2 == node1Prev) {
            node2->next = node1Next;
            node1Next->prev = node2;

            node1->next = node2;
            node2->prev = node1;

            node2Prev->next = node1;
            node1->prev = node2Prev;
        }
        else {
            if (node2Prev)
                node2Prev->next = node1;

            if (node2Next)
                node2Next->prev = node1;

            node1->prev = node2Prev;
            node1->next = node2Next;

            if (node1Prev)
                node1Prev->next = node2;

            if (node1Next)
                node1Next->prev = node2;

            node2->prev = node1Prev;
            node2->next = node1Next;
        }
    }

    ListNode* quickSort(ListNode* head, ListNode* tail) {
        if (head == tail)
            return head;

        ListNode* pivot = head;
        ListNode* tmpHead = head;
        ListNode* tmpTail = tail;

        ListNode* newHead = head;
        ListNode* newTail = tail;

        while (tmpHead != tmpTail) {
            while (tmpHead != tmpTail && pivot->val <= tmpTail->val)
                tmpTail = tmpTail->prev;

            if (tmpHead != tmpTail) {
                if (tmpHead == head)
                    newHead = tmpTail;
                if (tmpTail == tail)
                    newTail = tmpHead;

                swapNodes(tmpHead, tmpTail);
                tmpHead = tmpHead->prev;
                swap(tmpHead, tmpTail);
            }

            while (tmpHead != tmpTail && tmpHead->val <= pivot->val)
                tmpHead = tmpHead->next;

            if (tmpHead != tmpTail) {
                if (tmpHead == head)
                    newHead = tmpTail;
                if (tmpTail == tail)
                    newTail = tmpHead;

                swapNodes(tmpHead, tmpTail);
                tmpTail = tmpTail->next;
                swap(tmpHead, tmpTail);
            }
        }

        if (newHead != pivot)
            quickSort(newHead, pivot->prev);

        if (newTail != pivot)
            quickSort(pivot->next, newTail);
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
    n1->prev = nullptr;

    n2->next = n3;
    n2->prev = n1;

    n3->next = n4;
    n3->prev = n2;

    n4->next = n5;
    n4->prev = n3;

    n5->next = nullptr;
    n5->prev = n4;

    ListNode* n0 = s.sortList(n1);
    while (n0 != nullptr) {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
