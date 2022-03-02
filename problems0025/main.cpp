#include <iostream>
#include <vector>
#include <algorithm>

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> lists = cut(head, k);

        ListNode* newHead = new ListNode();
        ListNode* curr = newHead;
        for (int i = 0; i < lists.size(); ++i) {
            if (i == lists.size() - 1 && !enough) {
                curr->next = lists[i];
            }
            else {
                auto p = reverse(lists[i]);
                curr->next = p.first;
                curr = p.second;
            }
        }

        ListNode* del = newHead;
        newHead = newHead->next;
        delete del;
        return newHead;
    }

private:
    pair<ListNode*, ListNode*> reverse(ListNode* head) {
        ListNode* newHead = new ListNode();
        ListNode* cur = head;
        while (cur) {
            auto tmp = newHead->next;
            newHead->next = cur;
            cur = cur->next;
            newHead->next->next = tmp;
        }

        return {newHead->next, head};
    }

    vector<ListNode*> cut(ListNode* head, int k) {
        vector<ListNode*> out;

        int count = 1;
        while (head) {
            if (count == 1)
                out.push_back(head);

            ListNode* tmp = head->next;
            if (count == k) {
                head->next = nullptr;
                count = 0;
            }

            ++count;
            head = tmp;
        }

        if (count == 1)
            enough = true;
        else
            enough = false;

        return out;
    }

private:
    bool enough;
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

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;

    ListNode* n0 = s.reverseKGroup(n1, 3);
    while (n0) {
        cout << n0->val << " ";
        n0 = n0->next;
    }
    cout << endl;
    cout << "---------------------" << endl;
    return 0;
}
