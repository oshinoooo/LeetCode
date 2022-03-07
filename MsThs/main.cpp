#include <iostream>
#include <vector>

using namespace std;

//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表，需要实际的进行节点交换

class ListNode {
public:
    int value;
    ListNode* next;
    ListNode(int val) : value(val), next(nullptr) {}
};

ListNode* reverse(ListNode* head) {
    if (!head || !head->next)
        return head;

    ListNode* newHead = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

ListNode* test(ListNode* head) {
    vector<ListNode*> nodes;
    ListNode* curr = head;

    while (curr) {
        nodes.push_back(curr);
        if (curr)
            curr = curr->next;

        ListNode* prev = curr;

        if (curr)
            curr = curr->next;

        prev->next = nullptr;
    }

    for (int i = 0; i < nodes.size(); ++i) {
        nodes[i] = reverse(nodes[i]);
    }

    for (int i = 1; i < nodes.size(); ++i) {
        nodes[i - 1]->next->next = nodes[i];
    }

    return nodes[0];
}


int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;


    ListNode* out = reverse(n1);

    while (out) {
        cout << out->value << " ";
        out = out->next;
    }
    cout << endl;
    return 0;
}
