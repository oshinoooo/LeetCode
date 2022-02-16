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

struct ListNode{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int v) : val(v), next(nullptr) {}
    ListNode(int v, ListNode* n) : val(v), next(n) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }

    ListNode* sortList2(ListNode* head) {
        if (!head)
            return nullptr;

        ListNode* newHead = new ListNode(0, head);
        quickSort(newHead, nullptr);
        return newHead->next;
    }

private:
    ListNode* mergeSort(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* midd = findMid(head);

        ListNode* list1 = mergeSort(head);
        ListNode* list2 = mergeSort(midd);

        return mergeLists(list1, list2);
    }

    ListNode* mergeLists(ListNode* list1, ListNode*list2) {
        ListNode* newHead = new ListNode();

        ListNode* curr = newHead;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            }
            else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        if (list1)
            curr->next = list1;
        else if (list2)
            curr->next = list2;

        return newHead->next;
    }

    ListNode* findMid(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* prev = nullptr;
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

    void quickSort(ListNode* headPrev, ListNode* tailNext) {
        if (headPrev->next == tailNext)
            return;

        ListNode* pivot = headPrev->next;
        ListNode* prev = pivot;
        ListNode* curr = pivot->next;

        while (curr != tailNext) {
            if (curr->val <= pivot->val) {
                prev->next = curr->next;

                ListNode* tmp = headPrev->next;
                headPrev->next = curr;
                curr = curr->next;
                headPrev->next->next = tmp;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        quickSort(headPrev, pivot);
        quickSort(pivot, tailNext);
    }
};

int main() {
    cout << "---------------------" << endl;
    Solution s;
    ListNode* n1 = new ListNode(6);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(4);
    ListNode* n4 = new ListNode(1);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(3);
    ListNode* n7 = new ListNode(7);
    ListNode* n8 = new ListNode(8);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;

    ListNode* n0 = s.sortList(n1);
    while (n0) {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
