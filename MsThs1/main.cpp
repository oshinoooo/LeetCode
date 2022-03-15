#include <iostream>
#include <vector>

using namespace std;

//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表，需要实际的进行节点交换

struct ListNode {
    int value;
    ListNode* next;
    ListNode() : value(0), next(nullptr) {}
    ListNode(int val) : value(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : value(val), next(next) {}
};

class Solution {
public:
    ListNode* change(ListNode* head) {
        vector<ListNode*> lists;
        ListNode* curr = head;

        while (curr) {
            lists.push_back(curr);
            if (curr)
                curr = curr->next;

            ListNode* prev = curr;

            if (curr)
                curr = curr->next;

            if (prev)
                prev->next = nullptr;
        }

        for (int i = 0; i < lists.size(); ++i)
            lists[i] = reverse(lists[i]);

        for (int i = 1; i < lists.size(); ++i)
            lists[i - 1]->next->next = lists[i];

        return lists[0];
    }

private:
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
    cout << "--------------------" << endl;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);
    ListNode* n7 = new ListNode(7);
    ListNode* n8 = new ListNode(8);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;

    Solution s;

    ListNode* n0 = s.change(n1);
    while (n0) {
        cout << n0->value << " ";
        n0 = n0->next;
    }
    cout << endl;
    cout << "--------------------" << endl;
    return 0;
}